#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TokenFreq {
	string token;
	int freq;

	bool operator<(const TokenFreq& compareItem){
		return freq < compareItem.freq;
	}
	bool operator>(const TokenFreq& compareItem){
		return freq > compareItem.freq;
	}
};

vector<TokenFreq> tfVec;

//initializing functions
void matrixInit(vector<vector<int>>& matrix, int numRows, int numCols);
void getTokenFreqVec(string& istr, vector<TokenFreq>& tfVec);
void insertionSort(vector<TokenFreq>& tokFreqVector);
void selectionSort(vector<TokenFreq>& tokFreqVector); // 
void tokenizer(const string& str, vector<TokenFreq>& tfVec); //extracts words and freq to add
void addToken(vector<TokenFreq>& tokenMatrix, const TokenFreq& addedWord); //adds to vector
void ReplacePunctuation(string& str); //extra for growth
bool matrixContains(const TokenFreq& toFind, const vector<TokenFreq>& tfVec);


void matrixInit(vector<vector<int>>& matrix, int numRows, int numCols){
	matrix.resize(numRows);
	for (int i = 0; i < numRows; i++){
		matrix[i] = vector<int>(numCols);
		for (int j = 0; j < numCols; j++)
			matrix[i][j]=(i*j);
	}
}

void getTokenFreqVec(string& istr, vector<TokenFreq>& tfVec){
	tokenizer(istr, tfVec);
}

void insertionSort(vector<TokenFreq>& tokFreqVector){

	for (size_t i = 1; i < tokFreqVector.size(); i++){
		int max = tokFreqVector[i].freq;
		int j = i - 1;
			while (j >= 0 && max > tokFreqVector[j].freq){
			iter_swap(tokFreqVector.begin() + j, tokFreqVector.begin() + j+1);
			j -= 1;
		 }  //end while
				max = tokFreqVector[j + 1].freq;
		}	//end for
}

void selectionSort(vector<TokenFreq>& tokFreqVector){
	for (size_t i = 0; i < tokFreqVector.size(); i++){
		int min = tokFreqVector[i].freq;
		for (size_t j = i + 1; j < tokFreqVector.size();j++){
			if (min > tokFreqVector[j].freq){
				min = tokFreqVector[j].freq;
				iter_swap(tokFreqVector.begin() + i, tokFreqVector.begin() + j);
			}				
		}
	}
}



//using istringstream to delimit words by ' ' **works**
//identify if word is in matrix **Done**
//add word to matrix **Done**
void tokenizer(const string& str, vector<TokenFreq>& tfVec){
	//string editedString = str;
	//ReplacePunctuation(editedString);
	std::string word;
	std::istringstream iss(str);
	int count = 1;

	//extracting individual words
	while (iss >> word){

		for (size_t i = 0; i < word.length(); i++){
			word[i]=tolower(word[i]);
		}

		

		//creating item to add
		TokenFreq addedWord;
		addedWord.token = word;
		addedWord.freq = count;

		//adding frequency/word to  token matrix
		if (!matrixContains(addedWord, tfVec)){
			addToken(tfVec, addedWord);
		}
		else{
			int i = std::find_if(tfVec.begin(), tfVec.end(),
				[word](const TokenFreq& a) { return a.token == word; })
				- tfVec.begin();
			tfVec[i].freq += 1;
		}
	}
}

//seeing if there is a match in the matrix
bool matrixContains(const TokenFreq& toFind, const vector<TokenFreq>& tfVec){
	
		auto iter = std::find_if(tfVec.begin(), tfVec.end(),
			[&](const TokenFreq& ts)
		{
			bool answer = (ts.token == toFind.token);
			
			return answer; });
		return iter != tfVec.end();
}


//removes punctuation from oringal adds spaces to ensure stream works correctly
void ReplacePunctuation(string& str){
	while (!isalnum(str.at(0))){
		str.erase(0, 1);
	}
	for (size_t i = 0; i < str.size(); i++){
		if (ispunct(str.at(i))){
			if (str.at(i) != '\'')
			str.replace(i, 1, " ");
		}
	}
}
void function1(int x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

//adds token to vector
void addToken(vector<TokenFreq>& tfVec, const TokenFreq& addedWord){
	tfVec.push_back(addedWord);
}

int main(){
	vector<vector<int>> Tokens;
	std::string sentence;
	matrixInit(Tokens,3, 4);
	getline(cin, sentence);
	tokenizer(sentence,tfVec);

	selectionSort(tfVec);
	insertionSort(tfVec);

	int sum = 0, row = 0, col = 0;
	int count = 0;
	for (row = 1; row < 8; row = row + 1){
		for (col = row; col < 5; col = col + 1){
			sum += row*col;
			count++;
		}
	}
	cout << count;

	int x = 17, y = 122;
	function1(x, y);
	cout << x << " " << y;
	system("PAUSE");
	
	
	
}