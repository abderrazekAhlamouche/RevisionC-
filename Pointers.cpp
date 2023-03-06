#include"Pointers.h"
 using namespace std;

		//Important Notes 


	//	Pointer declaration

	//int* pi or int* pi (no difference) 
	//=> pi is a pointer to an integer 

	//& before a variable means the "adress of"
	//int j = 4 \n pi = &j  => pi points to the adress of j 

	//the star symbol (*) before a variable name means "content of"
	//*pi=3  => changes the value of j

	//the operator -> after a pointer to an object is used to call a member function or variable (if public ) of that object 
	//it is the same (*pointer).

	//incrementing a pointer makes it point somewhere else 

	//Warning : Pointers arithmetics may be a great source of bug


void Pointers::examples()
{

		
		//Pointer Examples
		

		//example of pointer to variable

	int* pi; 
	int j = 2;
	pi = &j;

	cout << "Value of pi : " << pi << " value of *pi:" << *pi << " value of j : " << j << "\n";

	      //changing the value of *pi
	*pi = 8;
	cout << "value of *pi : " << *pi << " value of j : " << j << "\n\n";

		//example of pointer to object

	class Test {
		const std::string msg;
	public : 
		Test(const std::string &str):msg(str) {}
		const std::string getmessage()const { return msg; }
	};

	Test test("this is a message ");
	Test* test_p = &test;

	//calling the test class methode getMessage using the operator -> 

	cout <<"message stored in the test object test_p->getmessage(): "<< test_p->getmessage() << "\n";
}



void Pointers::execute() {
	std::map<int, int> limits = { {3, 25},{30, 59} };
	Context::execute(limits, "Pointers.cpp");
}