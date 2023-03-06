#include"Singleton.h"


class GlobalCoffeeConfig {
	std::map<std::string, std::string>  coffeeState;

	// Private constructor
	GlobalCoffeeConfig() {}

public:
	// Remove ability to use the copy constructor
	GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;

	// Remove ability top use the copy assignment operator
	GlobalCoffeeConfig& operator=(GlobalCoffeeConfig const&) = delete;

	// Provide a single, static method for retriving the singleton instance
	static GlobalCoffeeConfig& get() {
		static GlobalCoffeeConfig config;
		return config;
	}

	void setState(const std::string& key, const std::string& value) {
		coffeeState.insert({ key, value });
	}

	std::string getState(const std::string& key) {
		auto iterator = coffeeState.find(key);
		return iterator->second;
	}
};


void Singleton::examples(){

	//examples :
	// Can't compile this line because the constructor is private
		// GlobalCoffeeConfig configObj = GlobalCoffeeConfig();

		// The "get" method is the only way to retrive the static, singleton instance
		// This line doesn't compile, because the copy constructor has been removed - a new instance cannot be created
		// GlobalCoffeeConfig configObj = GlobalCoffeeConfig::get();

	GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();


	configObj.setState("COFFEE_STATUS", "ON");
	configObj.setState("COFFEE_HEALTH_URL", "./health");

	printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
	printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());

}

void Singleton::execute() {
	std::map<int, int> limits = { {3, 32},{35, 52} };
	Context::execute(limits, "Singleton.cpp");
}