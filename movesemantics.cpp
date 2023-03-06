#include"moveSematics.h"
#include<chrono>
#include <iterator>  //for using back_inserter 
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std; 
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

	//Important Notes
//move semantics allow to avoid coping and temporary varible 
//className&& rrx - an rvalue reference to some
//disappearing instance of Resource
//What’s an Rvalue ?
//x = 3;
//x = a + b;
//Name refers to RHS, but actual definition is
//more subtle
//- It is something ephemeral
//- Perfect for stealing from
//
//Move Constructor, Move Assignment Operator
//Like copy constructorand assignment operator
//Faster: “steal” elements from the reference they are
//passed
//- Eg make my pointer point the same place as the
//reference’s pointer
//Should leave the passed reference in a valid state
//- Empty, null pointer, etc
//Already implemented for standard library classes like
//stringand vector
//- If your types are movable, vector resizing(and
//	much more) will be faster
//
//	The Rules You Think You Know Might Be Wrong
//	Pass by value
//	- If a temporary is passed to the function, it might be
//	moved, not copied
//	Return by value
//	- That local variable is about to go out of scope –
//	compiler will move it
//	Is vector slow or not?
//	-When copying becomes moving, the heuristics
//	change
//	Is it inefficient to build a string from many little pieces ?
//	-Not if you move the pieces as you go
//
//	std::move doesn’t move anything
//	It’s just a cast
//	name = std::move(r.name);
//It causes the compiler to choose move
//constructors or move assignment operators
//- They might move something
//
//Rule of 3
//If you write a
//destructor, copy
//constructor, or
//assignment operator,
//write all three
//
//Rule of 5
//Add move constructor
//and move assignment
//operator to those three
//
//Rule of 0
//Use member variables
//that manage
//themselves(eg vector,
//	unique_ptr) and write
//	nothing
//
//	Standard Library uses move semantics
//	- All the collections
//	- string

//function allows the time spent in a function 
template <typename func >
long long TimeFunc(func f) {
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();
	return duration_cast<milliseconds>(end - begin).count();
}


//templates fonction that can have a template containe and set it with sizen strings 
template <typename T>
void exercise(int size, string commonname)
{
	//template collection
	T v; 
	//template object of which the collection will be fulled of 
	T::template value_type res1("starting entry"); 
	v.push_back(res1);
	//this loop generate a string of size caracter 
	//create an object initialized with that string 
	//push it to the collection at the begenning or at the end 
	for (int i = 0; i < size; i++)
	{
		int r = (int)rand();
		string s;
		int ss = r % 100;
		s.reserve(ss);
		std::generate_n(back_inserter(s), ss, [ss]() {return (char)('!' + ss / 2); });
		T::template value_type res(s);
		bool inserted = false;
		for (auto it = begin(v); it != end(v); it++)
		{
			if (*it > res)
			{
				v.insert(it, res);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			v.push_back(res);
	}

	auto it = max_element(begin(v), end(v));
	T::template value_type maxV = *it;
	it = min_element(begin(v), end(v));
	T::template value_type minV = *it;

	bool sorted = is_sorted(begin(v), end(v));
}

void MoveSemantics::examples(){

		//examples
		
	//create a class for test 
	class Resource
	{
	private:
		std::string name;
	public:
		Resource(std::string n):name(n){}
		Resource(const Resource& r) :name(r.name) {};
		Resource& operator=(const Resource& r)
		{
			name = r.name;
			return *this;
		}
		////move constructor
		// warning: paremeter cannot be const
		//Resource(Resource&& r) :name(std::move(r.name)) {};
		////move assignment operator 
		//Resource& operator=(Resource&& r)
		//{
		//	if (this != &r)
		//	{
		//		name = std::move(r.name);
		//		r.name.clear();
		//	}
		//	return *this; 
		//}
		~Resource(){};
		//this operator overloads are necessary to sort a collection of this object 
		bool operator>(const Resource& r) { return name > r.name; }
		bool operator<(const Resource& r) { return name < r.name; }
		bool operator==(const Resource& r) { return name == r.name; }
		//getter 
		std::string GetName() const { return name; }
	};


	//we are benchmarking the use of list and vectors 
	//we are fulling the a list and vector with 1000 string and measuring the time spent using chrono 
	//the use of lambda here is mandatory as TimeFunc acceptes a function with no parms
	//our execise is called in the lambda 
	//results : 
	//without move ctor and move assignment operator vector time : 1000ms list time = 324
	//with move ctor and move assignment operator vector time : 440ms list time = 324
	//withoutcopy ctor copy, assignment operator, move ctor and move assignment operator vector time : 406ms list time = 364
	//Important : if the memeber varible is movable like string in our case , then the compiler will perform the moving for us 
	const int size = 1000;

	auto vectormilliseconds = TimeFunc([&]() {exercise<vector<Resource>>(size, "vector"); });
	auto listmilliseconds = TimeFunc([&]() {exercise<list<Resource>>(size, "list"); });

	cout << "vector time for inserting 1000 strings :" << vectormilliseconds << endl;
	cout << "list time for inserting 1000 strings :" << listmilliseconds << endl;

}
void MoveSemantics::execute(){
	std::map<int, int> limits = { {15, 83},{137, 192} };
	Context::execute(limits, "movesemantics.cpp");
}