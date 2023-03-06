#include "Lambda.h"
#include<algorithm>
#include<vector>
#include<string>
#include<memory>
using std::vector;
using std::cout;

// Important Notes
//an expression thatrepresents doing something 
//benifits :
//-For generic work 
//-for a functional style 
//-for concurrency 
//-for readability 
//*eliminate tiny function

//[] capture clause => makes variables in the calling scope available and usable in the lambda
//() parameters 
//{} body
//compiler genrate a class and then an instance of that class iusing what put in the 3 parts of the lambda 
//compiler generates an anonymos function object 
//member variable controlled by capture clause  const by default 
//return type after -> 
//empty[]-capture nothing , use only function parameters 
//[x,y] capture x and y by value 
//copies by values 
//lambda can be used when x and y goes out of scope 
//[&x,&y] capture x and y by ref
//no copies , changes affect the originals 
//dangling ref may be an issue => x and y may goes out of scope and lambda capture are no more refered
//[x=a+1,y=std::move(b)] alias or move capture 
//let you execute an expression on the member variable of the lambda 
//[=] copy everthing by value (only what is used )
//[&] copy everything by reference (only what is used )
//mutable keyword => allows the changes of values captured by refrence 
//Warning:Labda not stored => capture by value /reference 
//Warning:Lambda store => capture by value 
//Warning:Use everything notation 
//when using return statement return type type infered by compiler 
//when compiler can't infer return type use ->
//exp : [](int n )->double{}

void Lambda::examples()
{


			//examples

	//declaring a lambda 
	auto isOdd = [](int number) {return number % 2 != 0;  };
	//using a lambdaas condition in algorith fct 
	vector<int> v1 = { 1,2,3,4,5 };
	//counts the odd nbr in v1 
	int odds = std::count_if(v1.begin(), v1.end(), isOdd);

	cout << "v1 has : " << odds << " odd nbrs \n"; 

	//declaring lambda and calling it at the same time 
	int evens = std::count_if(v1.begin(), v1.end(), [](int nbrs) {return nbrs % 2 == 0;  });//counts even nunbrs

	cout << "v1 has : " << evens << " even nbrs \n";


	//capturing examples 

	int x = 1; 
	int y = 5;
	std::string message = "elemens between "; 
	message += std::to_string(x) + " and " + std::to_string(y) + " inclusive : "; 

	std::for_each(v1.begin(), v1.end(), [x, y, &message](int n) {
		if ((n > x) && (n < y))
			message += std::to_string(n);
		});
	//because lessage is passed to the lambda by ref , its value can be changed 
	cout << message << "\n";

	//mutable lambda example 
	x = y = 0;
	//capturing everything by ref except x
	std::for_each(v1.begin(), v1.end(), [&, x](int n)mutable	
		{
			// this won't work unless the lambda is mutable 
			x += n; 
			y += n;
		});

	cout << "x= " << x << " y= " << y << "\n";

	//example of lambda with class 

	class A {
	public:
		std::string msg;
		A(std::string str):msg(str){}
		A(A const& a):msg(a.msg){}
	};
	//scoping braces
	{
		auto pA = std::make_unique<A>(" , ");
		message = "elemens between ";
		message += std::to_string(x) + " and " + std::to_string(y) + " inclusive : ";
		std::for_each(v1.begin(), v1.end(), [=, &message,p=std::move(pA)](int n)
			{
				if ((n > x) && (n < y))
					//Warning:this won't work unless we pass pA using std::move or passing it by reference
					//we can't copy a unique pointer 
					message += " "  + std::to_string(n) + p->msg;
			});

		//Warning:because the unique pointer pA was moved we can't use it anymore 
		cout << message + "\n";
	}

}

void Lambda::execute()
{
	std::map<int, int> limits = { {6, 16},{20, 112} };
	Context::execute(limits, "Lambda.cpp");
}