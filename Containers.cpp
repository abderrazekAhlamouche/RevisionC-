#include "Containers.h"
#include "vector.h"
#include "list.h"
#include "array.h"
#include "set.h"
#include "queue.h"
#include "deque.h"
#include "map.h"
#include "pair.h"
#include "stack.h"
#include "string.h"
#include "tuple.h"

   // Important Notes

//when the vector is auto resizing we'll need maybe copy constructor 
//as the vector will copy its current elements to the new one 
//keeps elements in memory consecutive
//fast random access 
//inserting is slow as it will need copying

//std::array is container in which the size never grow 
//this may improve performance 
//as it done on the stack 
//being able able to resize means that elements are kept on the heap 

//std::list implements linked list 
//each element knows where to find the next elements 
//saves the copying when new elements are added 
//Warning:elements access is slow

using std::vector;
using std::cout; 
using std::array;
using std::list;




void Containers::examples(){


	//examples

	//vector examples 

	//initialise vector 
	vector<int> v1; 

	//adding element
	v1.push_back(5); 
	v1.push_back(7); 

	for (auto i : v1) cout << "v1 elements : "<<i << "\n"; //displaying vector element 


	//creating an object 
	//to populate a vector
	class A {		
	public:																			
		int elem1;																	
		A(int e) :elem1(e) { cout << "calling ctor " <<elem1<< "\n"; };
	    A(const A& a):elem1(a.elem1) { cout << "calling copy ctor " << elem1<< "\n"; }
		/*A& operator=(const A& a) { this->elem1 = a.elem1; return *this; }*/
		//void operator = (A a) { A(a); }
		~A() { cout << "calling dtor "<< elem1<<"\n"; }
	};

	
	{ //scoping to see the destructors called 
		vector<A> v2;
		//insert objects
		v2.push_back(7);
		v2.push_back(1);
		v2.push_back(3);

		//display v2 
		for (A i : v2) cout << "v2 elements : " << i.elem1 << "\n";

	}

	cout << "\n\n\npick a container to see in more details  : \n";
	cout << "1-  vector \n"; 
	cout << "2-  array  \n";
	cout << "3-  list   \n";
	cout << "4-	 pair    \n";
	cout << "5-	 set    \n";
	cout << "6-	 map    \n";
	cout << "7-	 queue    \n";
	cout << "8-	 deque    \n";
	cout << "9-  stack   \n";
	cout << "10- tuple    \n";
	cout << "11- string	  \n";
	cout << "any other nmber: abort    \n";

	int choice = 0;
	cout << "choice : ";
	std::cin >>  choice; 

	Vector v;
	List l;
	Array a;
	Set st;
	Pair pr;
	Map mp;
	Queue qu;
	Deque dq;
	Stack stack;
	Tuple tuple;
	String str;
	switch (choice)
	{
	case 1: v.execute();
		break;
	case 2:a.execute();
		break;
	case 3:l.execute();
		break;
	case 4:pr.execute();
		break;
	case 5:st.execute();
		break;
	case 6:mp.execute();
		break;
	case 7:qu.execute();
		break;
	case 8:dq.execute();
		break;
	case 9:stack.execute();
		break;
	case 10:tuple.execute();
		break;
	case 11:str.execute();
		break;
	default:cout << "\n\n leaving ...";
	
	}
	

}

void Containers::execute() {
	std::map<int, int> limits = { {2, 12},{19, 71} };
	Context::execute(limits, "Containers.cpp");
}


template <typename T>
void Containers::message(const char* m, const T& v) { cout << m << ": " << v << std::endl; }





// print a simple message
void Containers::message(const char* s) { cout << s << std::endl; }
void Containers::message(const char* s, const int n) { cout << s << ": " << n << std::endl; }