#include"Factory_method.h"

class CoffeeMachine {
public:
	virtual void brew() = 0;
};

class SimpleCoffeeMachine : public CoffeeMachine {
public:
	void brew() {
		std::cout << "Brewing simple coffee \n";
	}
};

class RobustCoffeeMachine : public CoffeeMachine {
public:
	void brew() {
		std::cout << "Brewing robust coffee \n";
	}
};

// This factory class simply encapsulates the factory method for a CoffeeMachine type 
class CoffeeMachineFactory {
public:
	std::unique_ptr<CoffeeMachine> createMachine(int machineType) {
		switch (machineType) {
		case 1:
			return std::make_unique<SimpleCoffeeMachine>();
		case 2:
			return std::make_unique<RobustCoffeeMachine>();
		default:
			return std::make_unique<SimpleCoffeeMachine>();
		}
	}
};

void Factory_method::examples(){

	std::unique_ptr<CoffeeMachineFactory> factory = std::make_unique<CoffeeMachineFactory>();

	auto machineOne = factory->createMachine(1);
	auto machineTwo = factory->createMachine(2);

	machineOne->brew();
	machineTwo->brew();

}

void Factory_method::execute() {
	std::map<int, int> limits = { {2, 36},{38, 46} };
	Context::execute(limits, "Factory_method.cpp");
}