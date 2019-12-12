#include "Employee.h"
#include "Person.h"

int main(){
	Employee jonathan;
	
	for (int i = 0; i < 10; i++){
		cout << "This is Element " << i << " " << jonathan.getPlace(i) << endl;
	}
	system("pause");
	return 0;
}