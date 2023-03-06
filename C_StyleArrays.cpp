#include"C_StyleArrays.h"
#include<iostream>

		//Important Notes 


	//	array declaration

	//Declared with a type ; and an extent known at compile time 
	//int numbers[4] ; 

	//can be initialzed when declared 
	//double morenumbers[]={1.1;2.2;3.3;4.4;0};
	//=> extent is deduced by compiler 
	//Access on element with [], like vector exp : numbers[0] = 8 ;

	//can also use pointers to access 
	//use of just d means the adress of the first element of the array 
	//it acts as a pointer and can be incremented to loop the array 

	// Dynamic Arrays 
	//size is not known at compile time 
	//Use new[] to allocate memory on the heap 
	//clean up with delete[]
	//cannot resize: 
	//Create a larger one , copy elements , clean up the old one 

	//Warning : these arrays do not know how many elements they hold 
	//Warning : need to pass the size of the array 
	//Warning : do not bound check 



template<typename T>
void output(std::string const& msg, T* tab, int dim) {
	if (dim) {
		std::cout << "\n" + msg;
		for (int i = 0; i < dim; i++)
			std::cout << tab[i] << "\t";
	}
	else {
		std::cout << "\n" + msg << *tab;
	}
}

void C_StyleArrays::examples() {



	//arrays examples 

	//passing a variable as a dimension in array needs to be const 
	const int dim = 4; 
	int tab[4];

	//assignig values to tab 
	tab[0] = 8;
	tab[1] = 7;
	tab[2] = 6;
	tab[3] = 5;

	//displaying elements of the table 
	output("elements of int array :",tab,dim);

	//arithmetic addition with one to the elements of tab 
	for (int i = 0; i < dim; i++)
	{
		tab[i] += 1;
	}

	//displaying elements of the table 
	output("elements of int array :",tab, dim);

	//using pointer styple for addition for the second element
	*(tab + 1) = 1; 

	//displaying elements of the table 
	output("elements of int array :",tab, dim);

	//using double array
	double doubleTab[] = { 1.1, 2.2, 3.3, 4.4,0 };

	//arithmetic addition using a pointer 
	for (double* p = doubleTab; *p != 0; p++)
	{
		*p += 1.0; 
	}
	//calculation 
	double extent = doubleTab[1] + doubleTab[2];
	output("double array calculation result :",&extent);

	//displaying elements of the table 
	output("elements of double array : ",doubleTab, dim);

	//declare dynamic array 
	int* dynArray = new int[3];
	dynArray[0] = 4;
	dynArray[1] = 3;
	dynArray[2] = 2;

	//Warning:here we are going to add a value to an outside of the array dimension 
	//Warning:it will compile but we will write on someone else memory 
	//Warning:this can cause Runtime Error Heap_CORRUPTION
	//*(dynArray+3)=1;

	//displaying elements of the dynamic  table 
	output("elements of dynamic array : ",dynArray, 3);

	//methode to calculate the size of array 
	//Warning : this is not applicable in the case w execute *(dynArray+3)=1;
	int size = sizeof(tab) / sizeof(tab[0]);

	//displaying the size of tab 
	output("calculate size of int array :",&size);

	//Warning:we need to delete the dynamic array 
	delete[] dynArray;
} 

void C_StyleArrays::execute() {
	std::map<int, int> limits = { {3, 31},{48, 116} };
	Context::execute(limits, "C_StyleArrays.cpp");
}