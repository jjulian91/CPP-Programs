#include "Person.h"

class Person;

Person::~Person(){
	delete[] placesVisited;
	placesVisited = nullptr;
	cntPlaces = 0;
	
}
	//0->SSN, "na"->name, "personal@"->personalEmail, 10->cntPlaces, allocate space to placesVisited and initializes each place to "unknown"
Person::Person() :SSN(0), name("na"), personalEmail("personal@"), cntPlaces(10), placesVisited(new string[10]){
	for (int i = 0; i < cntPlaces; i++){
		placesVisited[i] = "unknown";
	}
}
Person& Person::operator=(const Person& rhs){
	delete[]this->placesVisited;
	this->placesVisited = nullptr;
	this->placesVisited = new string[cntPlaces];
	this->cntPlaces = rhs.cntPlaces;
		for (int i = 0; i < cntPlaces; i++){
			this->placesVisited[i] = rhs.placesVisited[i];
		}
		this->name = rhs.name;
		this->personalEmail = rhs.personalEmail;
		this->SSN = rhs.SSN;
	return *this;
}
	//copy constructor
	Person::Person(const Person &clone){
		cntPlaces = clone.cntPlaces;
		placesVisited = new string[cntPlaces];
		for (int i = 0; i < cntPlaces; i++){
			placesVisited[i] = clone.placesVisited[i];
		}
		SSN = clone.SSN;
		name = clone.name;
		personalEmail = clone.personalEmail;
	}
	//return the i-th place in the placesVisited array if i is valid; otherwise return "out-of-boundary".
	string Person::getPlace(int i) const{
		
		if (i < cntPlaces){
			return placesVisited[i];
		}
		else{
			return "out-of-boundary";
		}
	}

	//return personalEmail
	string Person::getEmail() const{
		return personalEmail;
	}
	//new_email-->personalEmail
	void Person::setEmail(string new_email){
		personalEmail = new_email;
	}
	//return "Person"
	string Person::getTypeOfObj() const{
		return "Person";
	}

