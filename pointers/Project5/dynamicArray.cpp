#include "dynamicArray.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /*time*/
#include <cstdlib>

//constructs array with ptr+i = i*i
int * array_constructor(int* &intPtr, int &size){
	if (size > 0){
		intPtr = new int[size];
		for (int i = 0; i < size; i++){
			intPtr[i] = i*i;
		}
	}
	return intPtr;
}

//creates new intPtr and assigns positions up to current size with current array
//fills array with i*i for additional positions
int * array_resize(int* &intPtr, int& currSize, int& newSize){
	if(currSize>=0 && newSize>0)
	{	
		int* newIntPtr = new int[newSize];
		
		for (int i=0; i < currSize; i++)
		{
			newIntPtr[i] = intPtr[i];
		}
		for (int i = currSize; i < newSize; i++)
		{
			newIntPtr[i] = i*i;
		}
		array_destructor(intPtr);
		intPtr = newIntPtr;
		return intPtr; 
	}
	else if (newSize < 0 || currSize == newSize)
		{
			return intPtr;
		}
	else if(newSize==0)
		{
			array_destructor(intPtr);
			return intPtr;
		}
	else
		{
			return intPtr;
		}
}

//deconstructs array
	void array_destructor(int* &intPtr){
	delete[] intPtr;
	intPtr = nullptr;
}



void array_set(int* &intPtr, int &size){
	 srand( time(NULL) );

	 for (int i = 0; i < size; i++){
		 intPtr[i] = rand();
	 }

}

void mysort(int* &intPtr, int size, bool(*comp)(int&, int&)){
	if (*comp == my_less_equal){
		for (int i = 1; i < size; i++){
			int min = intPtr[i];
			int j = i - 1;
			while (j >= 0 && min < intPtr[j]){
				intPtr[j] = intPtr[j + 1];
				j -= 1;
			}  //end while
			min = intPtr[j + 1];
		}	//end for
	}
	for (int i = 1; i < size; i++){
		int max = intPtr[i];
		int j = i - 1;
		while (j >= 0 && max > intPtr[j]){
			intPtr[j] = intPtr[j+1];
			j -= 1;
		}  //end while
		max = intPtr[j + 1];
	}	//end for
}

//return true if x<=y, false otherwise.
bool my_less_equal(int& x, int & y)  {
	return x <= y;
}

//return true if x>=y, false otherwise.
bool my_greater_equal(int& x, int & y){
	return x >= y;
}
