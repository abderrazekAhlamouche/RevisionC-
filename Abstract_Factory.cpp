#include"Abstract_factory.h"


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

class Coffee {
public:
	virtual void stir() = 0;
};

class SimpleCoffee : public Coffee {
public:
	void stir() {
		std::cout << "Stirring simple coffee \n";
	}
};

class RobustCoffee : public Coffee {
public:
	void stir() {
		std::cout << "Stirring robust coffee \n";
	}
};

// This is our abstract factory class
class CoffeeFactory {
public:
	virtual std::unique_ptr<CoffeeMachine> createMachine() = 0;
	virtual std::unique_ptr<Coffee> createCoffee() = 0;
};

// We can implement individual factories which include factory methods for a family of objects 
class SimpleCoffeeFactory : public CoffeeFactory {
public:
	std::unique_ptr<CoffeeMachine> createMachine() {
		return std::make_unique<SimpleCoffeeMachine>();
	}

	std::unique_ptr<Coffee> createCoffee() {
		return std::make_unique<SimpleCoffee>();
	}
};

class RobustCoffeeFactory : public CoffeeFactory {
public:
	std::unique_ptr<CoffeeMachine> createMachine() {
		return std::make_unique<RobustCoffeeMachine>();
	}

	std::unique_ptr<Coffee> createCoffee() {
		return std::make_unique<RobustCoffee>();
	}
};

void Abstract_factory::examples(){

	// We can use the abstract factory pattern to create families of related objects
	std::unique_ptr<CoffeeFactory> factoryOne = std::make_unique<SimpleCoffeeFactory>();
	auto coffeeMachineOne = factoryOne->createMachine();
	auto coffeeOne = factoryOne->createCoffee();

	auto factoryTwo = std::make_unique<RobustCoffeeFactory>();
	auto coffeeMachineTwo = factoryTwo->createMachine();
	auto coffeeTwo = factoryTwo->createCoffee();


	coffeeMachineOne->brew();
	coffeeOne->stir();

	coffeeMachineTwo->brew();
	coffeeTwo->stir();

}

void Abstract_factory::execute() {
	std::map<int, int> limits = { {3, 71},{73, 89} };
	Context::execute(limits, "Abstract_factory.cpp");
}