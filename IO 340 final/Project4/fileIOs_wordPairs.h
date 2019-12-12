
#ifndef FILEIOS_WORDPAIRS_H_
#define FILEIOS_WORDPAIRS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <istream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;



bool sentenceSplitter(string& fname, vector<string>& sentences);
bool wordpairMapping(vector<string>& sentences, map< pair<string, string>, int> &wordpairFreq_map);
bool freqWordpairMmap(map< pair<string, string>, int> &wordpairFreq_map, multimap<int, pair<string, \
	string> > &freqWordpair_mmap);
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, \
	int topCnt, int botCnt);


#endif

