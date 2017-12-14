/*-------------------------------- BASIC PROGRAM */

#include <iostream>
int main(int argc, char** argv)
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

/*----------------------------- ARRAY DEFINITION */

int* myArray[30]; 							// Compilation time -> Stack

int* myArray = new int[arraySize];			// Run time -> Heap (needs delete)
delete[] myArray;

/*------------------------------------ FUNCTIONS */

void addOne(int& i)											
{
	i++; 									// changes the original variable
}

typedef void (*funcptr)(int&);				// function pointer type
funcptr MyPtr = addOne;						// pointer to a function

/*------------------------------------- STRINGS */

#include <string>
#include <iostream>

using namespace std;

/*---------------------------------- FULL CLASS */

											// Calculator.h
class Calculator
{
	public: 								// external code can call
		Calculator(); 						// constructor
		~Calculator(); 						// destructor
		int add(int num1, int num2); 		// method
	
	protected: 								// external code can't access
		bool fAllowNegatives;
};

											// Calculator.cpp
#include <iostream>
#include "Calculator.h"

Calculator::Calculator()
{
	fAllowNegatives = false; 				// initialize the data member
}
Calculator::~Calculator(){}

int Calculator::add(int num1, int num2)
{
	if (!getAllowNegatives() && (num1 < 0 || num2 < 0)) {
		std::cout << "Illegal negative number passed to add()" << std::endl;
		return 0;
	}
	return num1 + num2;
}
bool Calculator::getAllowNegatives()
{
	return fAllowNegatives;
}
void Calculator::setAllowNegatives(bool inValue)
{
	fAllowNegatives = inValue;
}

int main(int argc, char** argv)
{
	Calculator myCalc = Calculator(); 		// stack-based
	myCalc.setAllowNegatives(true);
	int result = myCalc.add(2, 2);

	Calculator* myCalc2; 					// heap-based
	myCalc2 = new Calculator(); 			// allocate a new object
	myCalc2->setAllowNegatives(false);
	int result2 = myCalc2->add(2, 2);

	return 0;
}

/*--------------------------------------- LOOPS */

for (int i=0; i<10; i++) {}

int i = 10;
while (i > 0) {
    cout << i << endl;
    i—-;
}

/*-------------------------------------- SWITCH */

switch (x) {
case 1:
    cout << “1” << endl;
case 2:
    cout << “2” << endl;
default:
    cout << “Something else” << endl;
}

/*------------------------------- MINIMUM CLASS */

class MyClass {
private:
    int x;
public:
    void MyFunction(int y);
};
void MyClass::MyFunction(int y) {
    x = y;
}

/*------------------------------- DERIVED CLASS */

class MyBase {
private:									// derived classes can not access this  
   int a;   
protected:   
   int b; 									// derived classes can access this  
};
class Derived : public MyBase {
private:
	int x;
public:
	Derived();
    void test() {
        b = 10;
    }	
};

/*------------------------------------ TEMPLATE */

template <typename T>
class MyTemplate {
public:
    T a;
};
MyTemplate<int> X;

/*------------------------------------ POINTERS */

int  var = 20;   							// actual variable declaration.
int  *ip;        							// pointer variable - *ip prints 20
ip = &var;       							// store address of var in pointer variable


void getSeconds(unsigned long *par);		// Pass pointer to a function

int main () {
   unsigned long sec = 0;
   getSeconds( &sec );
   return 0;
}

void getSeconds(unsigned long *par) {
   cout << par << endl;						// Prints the value zero
   *par = time( NULL );
   return;
}

/*---------------------------------- DECORATORS

static -> declares members that are not bound to class instances
const -> prevent the programmer from modifying it
virtual -> member functions whose behavior can be overridden in derived classes
abstract -> cannot be instantiated

*/