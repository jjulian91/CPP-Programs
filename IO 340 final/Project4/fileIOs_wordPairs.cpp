#include "fileIOs_wordPairs.h"
#include <sstream>
#include <algorithm>
#include <fstream>
#include <set>



using namespace std;
typedef map<pair<string, string>, int> pairMap;

bool sentenceSplitter(std::string& fname, vector<string>& sentences){

	ifstream fileSource;
	stringstream inputBuffer;
	string input;
	vector<string> temp1;
	string str;


	//Open file; 
	fileSource.open(fname);
	if (!fileSource.is_open()){
		std::cout << "Error opening file" << endl;
		return false;
	}

	//read in file to inputBuffer;	
	inputBuffer << fileSource.rdbuf();

	fileSource.close();  //close file

	//split sentences by new line first;
	while (getline(inputBuffer, input)){
		size_t prev = 0, pos;
		//split sentences by . and ?
		while ((pos = input.find_first_of(".?", prev)) != std::string::npos)
		{
			while (input.at(prev) == '\"' || isspace(input.at(prev))){
				prev++;
			}

			//checks next char for a " and includes it in string
			if (pos > prev){
				str = input.substr(prev, pos - prev);
				sentences.push_back(str);
				prev = pos + 1;
			}
		}


		if (prev < input.length())
			sentences.push_back(input.substr(prev + 1, std::string::npos));
		temp1.push_back(input);
	}
	cout << sentences.size();
	return true;
}

bool wordpairMapping(vector<string>& sentences, pairMap &wordpairFreq_map){
	pair <pairMap::iterator, bool> check;
	vector<pair<string, string>> pairList;

	//iterates every sentence in vector individually
	for (string sentence : sentences){
		set <string> wordList;
		string word;
		stringstream iss(sentence);
		//separates words into list
		while (iss >> word){
			transform(word.begin(), word.end(), word.begin(), ::tolower); //sets all to lowercase. 
			wordList.insert(word);
		}
		
		//puts wordlist into pairs in vector
		int position = 1;
		for (string word : wordList){
			set<string>::iterator i = wordList.begin();
				for (advance(i, position); i != wordList.end(); i++){
					pair <string, string> pair(word, *i);
					pairList.push_back(pair);
			}
			position++;
		}
		
	}
	for (pair<string, string> item : pairList){
		check = wordpairFreq_map.insert(make_pair(item, 1));
		if (check.second == false){
			pairMap::iterator it;
			for (it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); it++){
				pair<string, string> pair;
				pair = it->first;
				if (pair == item){
					int count = it->second;
					count++;
					it->second = count;
				}
			}
		}
	}

	return true;
}

bool freqWordpairMmap(pairMap &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap){
	pairMap::iterator it;
	for (it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); it++){
		pair<string, string> pair;
		int count;
		pair = it->first;
		count = it->second;
		freqWordpair_mmap.insert(make_pair(count, pair));
	}

	return true;

}

void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){
	multimap<int, pair<string, string> >::iterator it = freqWordpair_multimap.begin();

	ofstream fileOut(outFname);
	for (int i=0; i < topCnt; i++){
		pair<string, string> pair;
		int count;
		pair = it->second;
		count = it->first;
		fileOut << "< " << pair.first << ", " << pair.second << ">: " << count << endl;
		it++;
	}
	it = freqWordpair_multimap.end();
	for (int i=0; i < botCnt; i++){
		pair<string, string> pair;
		int count;
		pair = it->second;
		count = it->first;
		fileOut << "< " << pair.first << ", " << pair.second << ">: " << count << endl;
		it--;
	}
}



