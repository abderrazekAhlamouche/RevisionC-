#include"Solid.h"

void Solid::examples() {

	//SOLID Design Principles
	//	A set of object - oriented design principles that aim to help developers
	//	write code that is easily extensible, maintainableand more reusable.

	//The SOLID Principles are a good
	//	base for implementing objectoriented design patterns.

	//	SOLID Principles

	//	Open - closed
	//	Open for extension,closed for modification

	//	Single - responsibility
	//	Classes should have a , single purpose

	//	Liskov Substitution
	//	Behavioral class substitution

	//	Interface Segregation
	//	Favor multiple, specific ,interfaces over a single interface

	//	Dependency Inversion
	//	Depend on abstractions not implementations

	//	Single - responsibility Principle examples 

	//	important : whay not to do 


	//	class CoffeeMachine
	//{
	//	. . .

	//		void pourCoffee()        //    This method belongs hereand contains code that is specific to the responsibility of a CoffeeMachine
	//	{
	//		std::cout << ”Pouring coffee”;
	//	}
	//	void sendCoffeeMetrics()   // This method contains implementation details that are not specific to a CoffeeMachine
	//	{
	//		std::cout << ”Sending metrics”;
	//		UrlRequest request;
	//		request.uri(“ / metrics”);
	//		. . .
	//			request.perform();
	//	}
	//}

	//	Important: what to do

	//	class CoffeeMachine
	//	{
	//	. . .
	//		void pourCoffee()
	//	{
	//		std::cout << ”Pouring coffee”;
	//	}
	//	void sendCoffeeMetrics()      //This updated method is not concerned with the details of sending metrics
	//	{
	//		std::cout << ”Sending metrics”;
	//		coffeeService.sendMetrics(metrics)
	//	}
	//	}

	//	Open - closed Principle examples 

	//		Important : whay not to do 

	//		class CoffeeMachine {
	//		. . .
	//		private:
	//			// Settings are fixed
	//			vector<int> settings = { 1, 2, 3 } //Any time a new roast setting needs to be added, this code needs to update
	//				void roastBySetting(int setting) {   //This class is not easily extensible, and it encourages direct code modification
	//				// Ensure that setting is included
	//				// in valid settings
	//				switch (setting) {
	//				case 1:
	//					. . .
	//				case 2:
	//					. . .
	//				}
	//			}
	//	}

	//		Imprtant : what to do 

	//			class CoffeeMachine {
	//			. . .
	//				// Settings are dynamic
	//				void roastBySetting(RoastSetting setting) {  //When a new RoastSetting is added, the CoffeeMachine class code does not need to 	update
	//				. . .
	//					roastingService.roast(&setting) //If the RoastSetting type changed, the CoffeeMachine class would still not need to be changed
	//			}
	//		}

	//		Liskov Substitution Principle example 

	//			Important : what to do 

	//			If type “A” is derived from type “B” then you should be able to substitute
	//			objects of type “B” for objects of type “A”.

	//			class Roaster {
	//			public:
	//				virtual void roast();
	//		}
	//		class CoffeeRoaster : Roaster {
	//		public:
	//			void roast() {
	//				// Specific coffee implementation
	//			}
	//		}
	//		class EspressoRoaster : Roaster {
	//		public:
	//			void roast() {
	//				// Specific espresso implementation
	//			}
	//		}
	//		. ..Usage
	//			void roast(Roaster roaster) {  //Outside functions can unknowingly use either the coffee or espresso implementation
	//			roaster.roast() // Doesn’t care about type
	//		}

	//		Interface Segregation Principle examples 

	//			Clients using your code should not be forced into depending upon
	//			methods or other abstractions that they don’t need.

	//			Important : what not to do 

	//		class AllInOneCoffeeMachine : Machine { //This class happens to need to implement all of the Machine methods
	//		public:
	//			void roast() …
	//			
	//			class Machine {
	//			public:
	//				virtual void roast();
	//				virtual void pour();
	//				virtual void grind();
	//		}	void pour() …
	//				void grind() …
	//		}
	//		class SimpleCoffeeMachine : Machine { //This class doesn’t need to implement all the Machine methods so this violates the ISP
	//		public:
	//			void pour() …
	//				// Has to implement unneeded methods
	//		}

	//		Important what to dp 

	//			struct Roaster { virtual void roast(); }  //Individual interfaces
	//		struct Pourer { virtual void pour(); }
	//		struct Grinder { virtual void grind(); }
	//		struct RobustMachine : Roaster, Pourer, Grinder {	//This class can inherit from multiple interfaces to bring in all the functionality that it needs
	//		}
	//		class AllInOneCoffeeMachine : RobustMachine {
	//		public:
	//			void roast() …
	//				void pour() …
	//				void grind() …
	//		}
	//		class SimpleCoffeeMachine : Pourer { //Individual interfaces allow clients to use only want they need
	//		public:
	//			void pour() …
	//		}

	//		Dependency Inversion Principle examples 

	//			High - level modules(classes which depend upon other, low - level classes
	//			of a program) should not depend on low - level modules directly.They
	//			should both depend upon an abstraction

	//			Important : what not to do 

	//			class CoffeeMachine {  //Low-level “module”
	//			vector<int> status;
	//			…
	//		}
	//		class CoffeeTest {   //High-level “module”
	//							//If the CoffeeMachine class implementation changes than the CoffeeTest class will need to change as well
	//			void start(CoffeeMachine& machine) {
	//				for (auto bit : machine.status) {
	//					// operate on status bits
	//				}
	//			}
	//		}

	//	Important : what to do 

	//		struct CoffeeStatusReader {  //Shared abstraction
	//		virtual vector<int> readStatus();
	//	}
	//	class CoffeeMachine : CoffeeStatusReader {  //Low-level “module”
	//		vector<int> status;
	//		void readStatus() {
	//			for (auto bit : status) {
	//			}
	//		}
	//		…
	//	}
	//	class CoffeeTest {						//The high-level module no longer depends upon the low - level module.The implementation of the low - level functionality can change without the high - level module
	//											//needing to change as well.
	//		void start(CoffeeStatusReader& reader) {
	//			reader.readStatus();
	//		}
	//	}


}

		




void Solid::execute() {
	std::map<int, int> limits = { {4, 100},{101, 211} };
	Context::execute(limits, "Solid.cpp");
}