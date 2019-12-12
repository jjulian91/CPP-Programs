#ifndef _ListADT_h_
#define _ListADT_h_
#include <ostream>


using namespace std;


class Node {
public:
	inline Node():value(0), next(nullptr){   };
	//implement this default constructor as an inline function using an initialization section. 0->value, nullptr->next 
	inline Node(int val):value(val), next(nullptr){  };
	//implement this constructor as an inline function using an initialization section. val->value, nullptr->next   
	int value;
	Node *next;
};

class ListADT{
	
private:

	Node *head; //point to the first node on the linked list
	int size;  //number of nodes on the linked list

public:
	ListADT();
	~ListADT();
	 ListADT(const ListADT& copy);
	void operator=(const ListADT& copy);
	void push_back(int val ); 
	void push_front(int val);
	void pop_back();
	void pop_front(); 
	int operator[](int position);
	friend ostream &operator<< (ostream& output, const ListADT &list);
	int length() const;
};


#endif 