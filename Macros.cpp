#include"Macros.h"



//Important Notes


//#define PI 3.14 : substutution of name

//used somtimes to make function 

//#define SQR(X) (X*X)
//cause problem  if written wrongly 
//exp: SQR(1+1) will expand (1+1*1+1) = 3

//it is a preprocesseur directives
//Whenever a macro name is encountered by the compiler,
//it replaces the name with the definition of the macro.

#define ARRAYSIZE 5
#define SQ(X) ((X)*(X))

#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

#define ELEMENTS 1, \
            2, \
            3



void Macros::examples()
{


	//examples

//#define ARRAYSIZE 5
//#define SQ (X) ('X)*(X))

	std::cout << "ARRAYSIZE : "<<ARRAYSIZE << std::endl; 
	std::cout << "SQ(ARRAYSIZE) : " << SQ(ARRAYSIZE) << std::endl;
	
	//Chain Macros
//#define INSTAGRAM FOLLOWERS
//#define FOLLOWERS 138

	//INSTAGRAM is expanded first to produce FOLLOWERS.
	//Then the expanded macro is expanded to produce the outcome as 138. This
	std::cout << "this person has have " << INSTAGRAM << " followers" << std::endl;

	// Multi-line Macro definition
//#define ELEMENTS 1, \
//            2, \
//            3
	// Array arr[] with elements
	// defined in macros
	int arr[] = { ELEMENTS };
	std::cout << "arr elements : ";
	for (int i = 0; i < 3; i++) {
		printf("%d  ", arr[i]);
	}


}

void Macros::execute() {
	std::map<int, int> limits = { {3, 29},{34, 64} };
	Context::execute(limits, "Macros.cpp");
}