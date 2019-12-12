#include <iostream>
#include "dynamicArray.h"
#include <cstdlib>
using std::endl;

int main(){
	int size = 14;
	int* intPtr = new int[size];

	array_constructor(intPtr, size);
	int newSize = 28;
	array_resize(intPtr, size, newSize);
	system("PAUSE");
	array_destructor(intPtr);
	array_set(intPtr, size);
	mysort(intPtr, newSize, my_less_equal);

}