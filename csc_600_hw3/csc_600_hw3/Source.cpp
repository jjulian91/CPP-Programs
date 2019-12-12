/**
* Written by: jonathan Julian
* Date: 10/10/19
* CSC 600 hw 1.3
*/


#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int maxLen(int numberArray[], const int &size);
void bigInt(const int &n);
void reduce(int numArray[],  int &size);
double sec(void){return double(clock()) / double(CLOCKS_PER_SEC);}
int frec(int number);
int fit(int number);
int bs(int *bsArray, int begin, int size, int value);
int ibs(int *bsArray, int begin, int size, int value);

int main(){
	time_t total = 0, start = 0, end = 0;
	
	{//Section 1
		cout << "Section one output " << endl;
		const int size = 14;
		int numberArray[size] = { 1, 1, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };
		cout <<"Max count in array  " << maxLen(numberArray, size) << endl;
	}

	{//Section 2
		//gets value
		cout << "Section 2 output " << endl;
		int number = 1234567890;
		cout << "Number to make big :" << number <<endl;
		bigInt(number);
	}

	{//Section 3
		cout << "Section 3 output " << endl;
		int size = 17;
		int arraytoReduce[17] = { 9, 1, 1, 6, 7, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };
		cout << "Array before reducing ";
		for (int i = 0; i < size; i++){
			cout << arraytoReduce[i] << ", ";
		}
		reduce(arraytoReduce, size);
		cout << endl << "Array after reducing ";
		for (int i = 0; i < size; i++){
			cout << arraytoReduce[i] << ", ";
		}
		cout << endl;
	}
	{//section 4
		cout << "Section 4 output " << endl;
		int maxSize = 9999999;
		int *sortedArray = new int[maxSize];
		for (int i = 0; i < maxSize; i++){
			*(sortedArray + i) = i;
		}
		int K = 3;
		start = sec();
		for (int j = 0; j < K; j++)
			for (int i = 0; i < maxSize; i++)
				if (ibs(sortedArray, 0, maxSize-1, i) != i) cout << "\nERROR";
		end = sec();
		total = end - start;
		cout << "K is set to " << K << " and maxSize (j) is set to " << maxSize << endl;
		cout << "Total time for Iterative " << total << endl;

		start = sec();
		for (int j = 0; j < K; j++)
			for (int i = 0; i < maxSize; i++)
				if (bs(sortedArray, 0, maxSize - 1, i) != i) cout << "\nERROR";
		end = sec();
		total = end - start;

		cout << "Total time for recursive " << total << endl;
	}
	{//section 5
		cout << "Section 5 output " << endl;
		total = 0;
		
		int n10=0;
		//finding N10
		cout << "This begins finding the N10 fib number" << endl;
		while (total < 10){
			start = sec();
			frec(n10);
			end = sec();
			total = end - start;
			n10++;
		}
		cout << "the N10 Fib number is " << n10<<endl;
		start = sec();
		int value = frec(n10);
		end = sec();
		total = end - start; 
		cout << "total time to find N10 = "<<n10 << "for frec() is :  " << total << " and returned a value of  " << value << endl;

		start = sec();
		value = fit(n10);
		end = sec();
		total = end - start;
		cout << "total time to find N10 = "<<n10 << "for fit() is :  " << total << " and returned a value of  "<< value << endl;
		
		
	}
	system("Pause");
	return 0;
}

int maxLen(int numberArray[], const int &size){
	int currentVal = NULL, maxCount = 0, currentCount = 1;

	if (*(&numberArray+1)-numberArray > 0 )
		int currentVal = numberArray[0];
	else { return 0; }

	for (int i = 0; i < size; i++){
		if (numberArray[i] == currentVal){
			currentCount++;
			if (currentCount >= maxCount)
				maxCount = currentCount;
		}
		else{
			currentVal = numberArray[i];
			currentCount = 1;
		}
	}

	return maxCount;
}

void bigInt(const int &n){
	//gets value
	string firstRow, secondRow, thirdRow, fourthRow, fifthRow, sixthRow, lastRow;
	int number = n;
	int rem;
	for (int i = 0; number > 0; i++){
		rem = number % 10;
		number = number / 10;
		
		//identify digit
		switch (rem){
			case 0:
				firstRow = " @@@@@   " + firstRow;
				secondRow = "@@   @@  " + secondRow;
				thirdRow = "@@   @@  " + thirdRow;
				fourthRow = "@@   @@  " + fourthRow;
				fifthRow = "@@   @@  " + fifthRow;
				sixthRow = "@@   @@  " + sixthRow;
				lastRow = " @@@@@   " + lastRow;
				break;
			case 1:
				firstRow = "  @@     " + firstRow;
				secondRow =" @@@     " + secondRow;
				thirdRow = "  @@     " + thirdRow;
				fourthRow = "  @@     " + fourthRow;
				fifthRow = "  @@     " + fifthRow;
				sixthRow = "  @@     " + sixthRow;
				lastRow = "@@@@@@   " + lastRow;
				break;
			case 2:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "     @@  " + secondRow;
				thirdRow = "     @@  " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "@@       " + fifthRow;
				sixthRow = "@@       " + sixthRow;
				lastRow = "@@@@@@@  " + lastRow;
				break;
			case 3:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "     @@  " + secondRow;
				thirdRow = "     @@  " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "     @@  " + fifthRow;
				sixthRow = "     @@  " + sixthRow;
				lastRow = "@@@@@@@  " + lastRow;
				break;
			case 4:
				firstRow = "@@   @@  " + firstRow;
				secondRow = "@@   @@  " + secondRow;
				thirdRow = "@@   @@  " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "     @@  " + fifthRow;
				sixthRow = "     @@  " + sixthRow;
				lastRow = "     @@  " + lastRow;
				break;
			case 5:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "@@       " + secondRow;
				thirdRow = "@@       " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "     @@  " + fifthRow;
				sixthRow = "     @@  " + sixthRow;
				lastRow = "@@@@@@@  " + lastRow;
				break;
			case 6:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "@@       " + secondRow;
				thirdRow = "@@       " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "@@   @@  " + fifthRow;
				sixthRow = "@@   @@  " + sixthRow;
				lastRow = "@@@@@@@  " + lastRow;
				break;
			case 7:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "     @@  " + secondRow;
				thirdRow = "    @@   " + thirdRow;
				fourthRow = "   @@    " + fourthRow;
				fifthRow = "  @@     " + fifthRow;
				sixthRow = " @@      " + sixthRow;
				lastRow = "@@      " + lastRow;
				break;
			case 8:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "@@   @@  " + secondRow;
				thirdRow = "@@   @@  " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "@@   @@  " + fifthRow;
				sixthRow = "@@   @@  " + sixthRow;
				lastRow = " @@@@@@@  " + lastRow;
				break;
			case 9:
				firstRow = "@@@@@@@  " + firstRow;
				secondRow = "@@   @@  " + secondRow;
				thirdRow = "@@   @@  " + thirdRow;
				fourthRow = "@@@@@@@  " + fourthRow;
				fifthRow = "     @@  " + fifthRow;
				sixthRow = "     @@  " + sixthRow;
				lastRow = "@@@@@@@  " + lastRow;
				break;
		}
	}
	cout << firstRow << endl << secondRow << endl << thirdRow << endl << fourthRow << endl << fifthRow << endl << sixthRow << endl << lastRow << endl;
}

//search first for the max values
//take max values then retraverse and delete/move items to replace the matches
void reduce(int numArray[], int &size){
	if (size < 3){ cout << "less than 3 elements " << endl;}
	int first, second, third; first = second = third = 0;
	for (int i = 0; i < size; i++){
		if (numArray[i] > first){first = numArray[i];}
		else if (numArray[i] > second && numArray[i] != first){second = numArray[i];}
		else if (numArray[i] > third && numArray[i] != second && numArray[i] != first){ third = numArray[i]; } 
	}
	int i, k = 0, j=1;
	for (i = 0; numArray[i]; i++){ numArray[i] = numArray[i + k]; if (numArray[i] == first || numArray[i] == second || numArray[i] == third){ k++; i--; j++; } }size -= j;
}

int frec(int number){
	if (number <= 0)
		return 0;
	else if (number == 1){
		return 1;
	}
	else{
		return frec(number-2)+frec(number - 1);
	}
}

int fit(int number){
	int x = 0, y = 1, z = 0;
	for (int i = 0; i < number; i++) {
		z = x + y;
		x = y;
		y = z;
	}
	return x;
}

int bs(int *bsArray,int begin ,int size, int value){
	int mid = (begin + size) / 2;
	//cout << mid<<endl;
	if (size < 0){
		cout << "Array is too small";
		return NULL;
	}
	if (*(bsArray+mid) == value)
		return *(bsArray + mid);
	else if (*(bsArray + mid) > value){
		return bs(bsArray, 0, mid - 1, value);
	}
	else{ return bs(bsArray, mid + 1, size, value); }
	
	return -1;

}

int ibs(int *bsArray, int begin, int size, int value){
	while (begin <= size){
		int mid = (begin + size) / 2;
		if (*(bsArray + mid) == value)
			return *(bsArray + mid);
		if (*(bsArray + mid) < value)
			begin = mid + 1;
		else{ size = mid - 1; }
	}
	return -1;
}