#include"StrategyPattern.h"
using namespace std;


	//Important Note

//Decouple algorithms from core logic
//Represent each algorithm by a Strategy class
//
//Problem Statement
//An application with finite goal
//Different algorithms to achieve that
//Choose appropriate algorithm at runtime
//Addition or modification of algorithms
//Leading to huge code change with errors
//
//How Strategy Pattern Addresses It
//Extract algorithms in separate classes
//Client passes required strategy
//Context class should refer to strategies
//
//steps:
//
//Identify algorithm
//Algorithm that’s prone to change frequently
//
//Declare strategy interface
//Should be implemented by all the strategy classes
//
//Extract algorithms to strategy classes
//These classes should inherit strategy abstract class
//
//Add reference field in context class
//Reference to the strategy interface
//
//Clients to pass strategy
//Clients need to be aware of the strategy to pass
//
//Improvements Brought by Strategy Pattern
//Swapping algorithms At runtime
//New strategies Without disturbance
//Isolate algorithms From implementation
//
//Demerits of Strategy Design Pattern
//Overcomplication If applied for a fewer algorithms
//Intelligent client Client to choose strategy




void StrategyPattern::examples() {

	//examples 

///**
// * The Strategy interface declares operations common to all supported versions
// * of some algorithm.
// *
// * The Context uses this interface to call the algorithm defined by Concrete
// * Strategies.
// */
	class Strategy {
	public:
		virtual ~Strategy() {}
		virtual void findRoute(string origin, string destination)const = 0;
	};

	class Context {
		Strategy* _strat; 
	///**
	// * Usually, the Context accepts a strategy through the constructor, but also
	// * provides a setter to change it at runtime.
	// */
	public:
		Context(Strategy* strat = nullptr) :_strat(strat) {}
		~Context() { delete this->_strat; }
	///**
	// * Usually, the Context allows replacing a Strategy object at runtime.
	// */
		void changeStrat(Strategy* strat) {
				delete _strat;
			this->_strat = strat;
		}
	///**
	// * The Context delegates some work to the Strategy object instead of
	// * implementing multiple versions of the algorithm on its own.
	// */
		void showMeRoute(string origin, string destination) {
			cout << "Context: Need to show an appropriate route. I don't know how to do it though\n";
			this->_strat->findRoute("house", "airport");
		}
	};
	///**
 //* Concrete Strategies implement the algorithm while following the base Strategy
 //* interface. The interface makes them interchangeable in the Context.
 //*/
	class CarStrategy :public Strategy {
	public:
		void findRoute(string origin, string destination)const
		{
			cout << "using car to go from " + origin + " to " + destination + "\n";
		}

	};

	class BusStrategy :public Strategy {
	public:
		void findRoute(string origin, string destination)const
		{
			cout << "using bus to go from " + origin + " to " + destination + "\n";
		}

	};

	Context *myMap = new Context(new CarStrategy);
	myMap->showMeRoute("house", "airport");
	myMap->changeStrat(new BusStrategy);
	myMap->showMeRoute("house", "airport");

}

void StrategyPattern::execute() {
	std::map<int, int> limits = { {4, 47},{52, 119} };
	Context::execute(limits, "StrategyPattern.cpp");
}