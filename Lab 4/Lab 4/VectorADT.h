#ifndef VectorADT_h
#define VectorADT_h
#include <ostream>
using namespace std;

class VectorADT
{
private:
	int size;
	int capacity;
	double * array;

public:
	VectorADT();
	~VectorADT();
	VectorADT(const VectorADT &oldVect);
	void operator= (const VectorADT& newVector);
	void push_back(double val);
	void resize(int newSize);
	void pop_back();
	double operator[](int position);
	VectorADT operator+(const VectorADT &RHS);
	friend ostream &operator<<(ostream& output, VectorADT &vector);
	int length() const;
	int curr_capacity() const;

};
#endif