#include <iostream>
#include "ListADT.h"
#include "VectorADT.h"

using namespace std;


int main(){
	ListADT list;
	cout << list.length();
	cout << list;	
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	
	cout << list.length();
	ListADT list2;
	list2 = list;
	cout << list2.length();
	ListADT list3 = list;
	cout << "list 3: " << list3.length() << list3 << endl << "list 2: " << list2.length() << list2 << endl << "original list: " << list.length() <<list << endl;
	system("PAUSE");

	return 0;
}
