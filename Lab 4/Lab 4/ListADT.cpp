#include "ListADT.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
class Node;
class ListADT;

ListADT::ListADT() :head(NULL), size(0){}
ListADT::~ListADT(){
	Node *temp = head;
	while (temp != nullptr){
		Node *next = temp->next;
		delete temp;
		temp = next;
	}

}
ListADT::ListADT(const ListADT& copy) :head(nullptr){
	size = copy.size;
	Node *current = new Node(copy.head->value);
	Node *copyTemp = copy.head;
	head = current;
	while (copyTemp->next != nullptr){
		copyTemp = copyTemp->next;
		current->next = new Node(copyTemp->value);
		current = current->next;
	}
}
void ListADT::operator = (const ListADT& copy){
	while (head != nullptr){
		pop_back();
	}
	size = copy.size;
	Node *current = new Node(copy.head->value);
	Node *copyTemp = copy.head;
	head = current;
	while (copyTemp->next != nullptr){
		copyTemp = copyTemp->next;
		current->next = new Node(copyTemp->value);
		current = current->next;
	}

}
void ListADT::push_back(int val){
	Node *newNode = new Node;
	newNode->value = val;
	if (size == 0)
		head = newNode;
	else {
		Node *Temp = head;
		while (Temp->next != nullptr){
			Temp = Temp->next;
		}
		Temp->next = newNode;
	}
	size++;
}
void ListADT::push_front(int val){
	Node *newNode = new Node;
	newNode->value = val;
	size++;
	newNode->next = head;
	head = newNode;
}
void ListADT::pop_back(){
	if (size > 0){
		Node *Temp = head;
		while (Temp->next->next != nullptr){
			Temp = Temp->next;
		}
		cout << Temp->value;
		Temp->next = nullptr;
		size--;
	}
}
void ListADT::pop_front(){
	if (size > 0){
		if (size == 0)
			head = nullptr;
		head = head->next;
		size--;
	}

}
int ListADT :: operator[](int position){
	if (position > size){
		return 0;
	}
	Node *current;
	current = head;

	for (int i = 0; i < position; i++){
		current = current->next;
	}
	int returnVal = (current->value);
	return returnVal;

}
ostream &operator << (ostream &output, const ListADT &list){
	Node *current;
	current = list.head;
	while (current != nullptr){
		output << current->value;
		current = current->next;
		if (current != nullptr)
			output << ", ";
	}
	output << endl;
	return output;

}
int ListADT::length() const{
	return size;
}
