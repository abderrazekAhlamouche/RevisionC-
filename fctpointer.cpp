#include"FunctionPointers.h"



//Important Notes


//Decide at runtime what function to execute : very powerful 

//declaration:

//typedef int (*changer)(int i ,int j );

//changer is a pointer to a function that takes two integer as parameter and returns an int 

//declare an instance : changer method ; 

//assign to a function name : method = calculate

//call : methode(a,b)

//fucntion pointer to a member function : 

//exp typedef int (utility::* UF)();

//include the class name when setting ip typedef 

// UF action 

//to set a value to action you need to add the class name and adress operator: 

//action = &Utility::triplex;

//call : return (U.*action)()

typedef int (*operation)(int i, int j);

int addition(int a, int b) { return a + b; }
int substraction(int a, int b) { return a - b; }



void FunctionPointers::examples()
{


			//examples

	//calling addition
	operation op;
	op = addition; 

	std::cout << "addition using op 4 + 5 = " << op(4 , 5) << std::endl;

	//calling substraction 
	op = substraction;

	std::cout << "addition using op 10 - 5 = " << op(10, 5) << std::endl;

}



void FunctionPointers::execute() {
	std::map<int, int> limits = { {3, 42},{45, 63} };
	Context::execute(limits, "fctpointer.cpp");
}