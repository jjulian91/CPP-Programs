# include "fileIOs_wordPairs.h"

#include<iostream>

using namespace std;

int main(){
	
	string fname = "SteveJobsSpeech2005-19.txt";
	vector<string> sentences; 
	multimap<int, pair<string, string> > freqWordpair_multimap;
	map< pair<string, string>, int> wordpairFreq_map;
	sentenceSplitter(fname, sentences); 
	wordpairMapping(sentences, wordpairFreq_map);
	printWordpairs(freqWordpair_multimap,fname,10,10);
	system("PAUSE");
	return 0;

}