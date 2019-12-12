#include "VectorADT.h"
#include <ostream>
#include <cstdlib>
#include <cstdio>

class VectorADT;
using namespace std;


VectorADT::VectorADT() {
	size = 0;
	capacity = 10;
	array = new double[this->capacity];
	for (int i = 0; i < capacity; i++){
		array[i] = 0.0;
	}
}


VectorADT::~VectorADT(){
	if (array != nullptr){
		delete[] array;
		array = nullptr;
	}
}

VectorADT::VectorADT(const VectorADT &oldVect){
	size = oldVect.size;
	array = new double[oldVect.capacity];
	capacity = oldVect.capacity;
	for (int i = 0; i < size; i++){
		*(array + i) = oldVect.array[i];
	}

}

void VectorADT::operator= (const VectorADT& otherVector){
	if (capacity == otherVector.capacity){
		for (int i = 0; i < otherVector.size; i++)
			array[i]=otherVector.array[i];
	}
	else{
		delete[] array;
		array = new double[otherVector.capacity];
		for (int i = 0; i < otherVector.size; i++)
			array[i] = otherVector.array[i];
	}
	size = otherVector.size;
	capacity = otherVector.capacity;
}

void VectorADT::push_back(double val){
	if (size < capacity){
		array[size] = val;
		size++;
	}
	else{
		resize(size+1);
		array[size-1] = val;
	}
} //done

void VectorADT::resize(int newSize){
	if (capacity >= newSize){
		if (size > newSize){
			for (int i = newSize; i < capacity; i++)
			{
				array[i] = 0.0;
			}
		}
		size = newSize;
	}
	else {
		capacity = newSize * 2;
		double* newArray = new double[capacity];
		for (int i = 0; i < size; i++){
				newArray[i] = array[i];
		}
		for (int i = size; i < capacity; i++){
			newArray[i] = 0.0;
		}

		delete[] array;
		array = newArray;
		size = newSize;
	}
} //done

void VectorADT::pop_back(){
	if (size > 1){
		size -= 1;
		(array[size]) = 0.0;
	}
	else if (size == 1){
		array[0] = 0.0;
		size--;
	}

} // done

double VectorADT :: operator[](int position){
	return array[position];
}

VectorADT VectorADT::operator + (const VectorADT &RHS){
	VectorADT sum;
	
	if (size != RHS.size){
		return sum;
	}
	else
	{
		for (int i = 0; i < size; i++)
			sum.push_back((RHS.array[i]) + *(array + i));
	}
	return sum;
}

ostream &operator<<(ostream& output, VectorADT &vector){
	for (int i = 0; i < vector.length(); i++){
		output << vector.array[i];
		if (i + 1 != vector.length())
			output << ", ";
		else{ output << endl; }
	}
	return output;
}

int VectorADT::length() const{
	return size;
}

int VectorADT::curr_capacity() const{
	return capacity;
}

