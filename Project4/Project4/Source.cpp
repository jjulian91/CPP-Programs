/*
* Author: Jonathan Julian
* Assignment 1.2
* Date: 9/27/2019
*/


#include <iostream>
#include <iomanip> 
#include <chrono>
#include <ctime>


double mysqrt(double value){
	//possible solution
/*	double _value = value;
	double x1 = 0 , sum = 0, d_places = 0, stepSize = 10000, offset = .1;
	//brute force.
	while (!(sum > _value) && d_places < 16){
		x1 += stepSize; //increment next step
		sum = x1*x1; //sqare value 
		if (sum > _value){ //check if sqaure is too large
			sum = 0; // reset sum for check 
			x1 -= stepSize; //decrease step by 1
			stepSize *= offset; //move decimal place one digit over
			if (stepSize < 1.) //increment decimal place counter.
				d_places++;
		}
	}
	*/

	
	double x1 = value, Xold;
	do
	{
		Xold = x1;
		x1 = (Xold + value / Xold) / 2;
	} while (x1 != Xold);
	return x1;
}

int main(void)
{
	//segment 1
	{
		std::cout << "\n\nSegment 1 output\n";
		unsigned int a = 4294967295, b = 1, c;
		c = a + b;
		std::cout << "a = " << a << "\nb = " << b << "\na + b = " << c <<"\n";
	}

	//segment 2
	{
		std::cout << "\n\nSegment 2 output\n";
		int a = 2147483647, b = 1, c;
		c = a + b;
		std::cout << "a = " << a << "\nb = " << b << "\na + b = " << c << "\n";
	
	}
	//segment 3
	{
		std::cout << "\n\nSegment 3 output\n";
		int a = -2147483647, b = -2, c;
		c = a + b;
		std::cout << "a = " << a << "\nb = " << b << "\na + b = " << c << "\n";
	
	}
	//segment 4
	{
		std::cout << "\n\nSegment 4 output\n";
		double a = 1.0, b = .0000001, c;
		c = a + b;
		std::cout << "a = " << a << "\nb = " << b << "\na + b = " << c << "\n";
	}
	//segment 5
	{
		//needs done still
		std::cout << "\n\nSegment 5 output\n";

		float a = 500000000, b = -500000000, c = 1;
		
		std::cout << "a = " << a << "\nb = " << b << "\nc = " << c <<"\n";
		std::cout << "( a + b ) + c = " << ((a + b) + c) << "\n( c + b ) + a = " << ((c + b) + a)<<"\n";
	}
	//segment 6
	{
		std::cout << "\npow(-2., 3) = " << pow(-2., 3) << "\npow(-2., 3.0)  = " << pow(-2., 3.0) << "\npow(-2., 3.00000000001) = " 
			<< pow(-2., 3.00000000001) <<"\n";
	}
	//segment 7
	{
		std::cout << "\n\nSegment 7 output\n";
		std::cout << "size of 1. " <<sizeof(1.) << " bits\nsize of 1.f " << sizeof(1.f) << " bits\nsize of 1 " << sizeof(1) 
			<< " bits\nsize of \'1\' " << sizeof('1') << " bits\nsize of \"1\" " << sizeof("1") << " bits";
	}
	//segment 8
	{
		std::cout << "\n\nSegment 8 output\n";
		double a = 3., b = 1., c;
		c = b/a;
		std::cout << std::setprecision(20) << "a = " << a << "\nb = " << b << "\nb/a = " << c << "\n";
	}
	//segment 9
	{
		std::cout << "\n\nSegment 9 output\n";
		for (int i = 32; i < 64; i++){
			int j = i;
			std::cout << char(j) << " " << j << "\t";
			j+=32;
			std::cout << char(j) << " " << j << "\t";
			j+=32;
			std::cout << char(j) << " " << j << "\n";
		}
	}
	{	
		std::cout << "\n\nSegment 10 output\n";
		std::cout << std::setprecision(13) << "The square root of 2 is approximately " 
			<< mysqrt(2.) << ".   The square root function returns " << sqrt(2.) << "\n";
	}
	system("pause");
}
