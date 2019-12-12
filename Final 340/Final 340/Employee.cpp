#include "Employee.h"

class Employee;
	Employee::~Employee(){
		delete this;
	}
	//0.0->salary, 10->cnt_sal_changes, "work@"->work_email, sal_change_rates: allocate memory to hold 10 doubles, 
	//each of which has an initial value of 0.0
	Employee::Employee():salary(0), cnt_sal_changes(10), work_email("work@"), sal_change_rates(new double[10]), Person(){
		for (int i = 0; i < 10; i++){
			sal_change_rates[i] = 0.0;
		}
	}
	Employee Employee::operator+=(const Employee& rhs){
		this->salary += rhs.salary;
		return *this;
	}
	Employee::Employee(const Employee& clone):Person(clone){
		salary = clone.salary;
		cnt_sal_changes = clone.cnt_sal_changes;
		work_email = clone.work_email;
		delete[]sal_change_rates;
		sal_change_rates = new double[cnt_sal_changes];
		for (int i = 0; i < cnt_sal_changes; i++){
			sal_change_rates[i] = clone.sal_change_rates[i];
		}
		
	}
	Employee Employee::operator=(const Employee& rhs){
		Person::operator=(rhs);
		this->salary = rhs.salary;
		this->work_email = rhs.work_email;
		if (this->cnt_sal_changes != rhs.cnt_sal_changes){
			this->cnt_sal_changes = rhs.cnt_sal_changes;
			delete[]this->sal_change_rates;
			this->sal_change_rates = new double[cnt_sal_changes];
		}
			for (int i = 0; i < cnt_sal_changes; i++){
				this->sal_change_rates[i] = rhs.sal_change_rates[i];
			}
		
		return *this;
	}

	////return the i-th rate in the sal_change_rates array if i is valid; otherwise return -1.00
	double Employee::getChangeRate(int i) const{
		
		if (i < cnt_sal_changes){
			return sal_change_rates[i];
		}
		else{
			return -1.00;
		}
	}
	//return work_email
	string Employee::getEmail() const{
		return work_email;
	}
	//new_email-->work_email
	void Employee::setEmail(string new_email){
		work_email = new_email;
	}
	//return "Employee"
	string Employee::getTypeOfObj() const{
		return "Employee";
	}
	//see below for more details about this function. 
	void mixedArray(Person** &arrayPersonEmp, int numPersons, int numEmployees){
		int size = numEmployees + numPersons;
		arrayPersonEmp = new Person*[size];
		for (int i = 0; i < size; i++){
			if (i < numPersons){
				 Person *P = new Person;
				 P->setEmail("personal@gmail.com");
				 arrayPersonEmp[i] = P;
			}
			else{
				Employee *E = new Employee;
				E->setEmail("work@gmail.com");
				arrayPersonEmp[i] = E;
			}
		}
	
	}

	//see below for more details about this function. 
	void deleteMixedArray(Person** &arrayPersonEmp, int size){
		for (int i = 0; i < size; i++){
			arrayPersonEmp[i]->~Person();
		}
		delete[]arrayPersonEmp;
		arrayPersonEmp = nullptr;
	}