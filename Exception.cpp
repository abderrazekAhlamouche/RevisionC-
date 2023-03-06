#include"Exception.h"
using namespace std;

	//Important note
//Transfer flow of execution
//Deal with things as close to the problem as possible
//
//Wrap code that might throw in a try block
//- as small as possible
//Add one or more catch blocks after the try
//Catch more specific exceptions first
//Catch exceptions by reference
//- Great for catching a derived exception
//No finally
//- That cleanup code belongs in a
//destructor
//- Destructors run no matter how control
//leaves the block
//
//C++ allows you to throwand catch
//anything
//- int, string, instance of a class
//Puts quite a burden on the developer
//Documentation might help
//- If it exists
//- If it mentions the exception
//
//std::exception
//Has a member function : what() - returns a
//string
//Has a number of derived classes
//- logic_error
//- runtime_error
//These are “marker classes”
//
//Unwinding the Stack
//When an exception is thrown
//If in a try, everything local to try block goes out of scope
//- Destructors go off
//- Control goes to the catch
//If not, everything local to the function goes out of scope
//- control returns to where that function was called from
//- Recurse to “if in a try” above
//If you get all the way out of main(), the user gets a dialog
//- But it’s more interesting when you end up in a catch
//
//Exceptions Have a Cost
//
//Don’t use for data entry validation(eg Feb 30th)
//
//If it’s thrown, time is used up(much more than an if)
//
//Little or no cost to set up a try / catch if the exception is not thrown
//
//Using exceptions makes neater code that
//runs faster when everything goes well
//- Best for rare occurrences like disk full,
//network fell down etc
//
//You Can Mark a Function as noexcept
//Advantages : expressivity, noexcept(false) performance
//Really means “won’t throw an exception worth catching”
//Appears to mean “won’t throw an exception”
//
//Enabling Moves with noexcept
//
//warning :If a move operation throws, the enclosing operation can’t be rolled back
//Important :Some moving operations in std::will only call noexcept functions
//- Move ctor, move op=, swap
//If your move operations(or things they call) are not noexcept, you’ll get a copy instead
//Mark these noexcept if you can


void Exception::examples() {

	//examples

	//class for testing examples
	class Noise
	{
	private:
		std::string SoundIMake;
	public:
		Noise(std::string str):SoundIMake(str){ std::cout << "Constructing Noise " << SoundIMake << std::endl; }
		~Noise(){ std::cout << "Destructing Noise " << SoundIMake << std::endl; }
	};

	class Person
	{
	private:
		std::string firstname;
		std::string lastname;
		int arbitrarynumber;

	public:
		Person(std::string first,
			std::string last,
			int arbitrary):firstname(first),lastname(last),arbitrarynumber(arbitrary){
			if (arbitrarynumber == 0)
			{
				throw invalid_argument("Arbitrary number for a Person cannot be zero.");
			}
		}
		Person():firstname(""), lastname(""), arbitrarynumber(-1) {}
		std::string GetName() const { return firstname + " " + lastname; }
		int GetNum() const { return arbitrarynumber; }

	};

	vector<int> v;
	v.push_back(1);
	Noise n1("beep 1");
	try
	{
		//this will loose scope once out of the try block 
		Noise n2("bloop 2");
		Person Kate("Kate", "Gregory", 0);
		//this will never be called as the precedent object instantiation throw an exception 
		int j = v.at(99);
	}
	catch (out_of_range& e)
	{
		cout << " out of range exception " << e.what();
	}
	//this catch will not be activated as the precedent one is filled 
	catch (exception& e)
	{
		cout << e.what();
	}


}
void Exception::execute() {
	std::map<int, int> limits = { {3, 72},{75, 131} };
	Context::execute(limits, "Exception.cpp");
}