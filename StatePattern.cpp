#include"StatePattern.h"
#include"StateExample.h"
#include <typeinfo>
using namespace std;

//Important Notes

//Allow object to alter its
//behavior when its state
//changes
//
//Figure out the context class
//Could be an existing class or a new class
//
//Declare state interface
//Focus on functions containing state
//specific behavior
//
//Create concrete state classes
//With a pair of methods to addand remove subscribers
//
//Add reference field in context class
//Reference to the State interface
//
//Call State object functions
//Replace empty conditionals with appropriate function calls in
//the State class
//
//Switch context state
//Create a State class objectand pass that to the context
//
//Improvements Brought by State Pattern
//
//Organizes code
//related to state
//
//Simplifies
//application
//
//Eases code
//expansion
//
//Runtime
//behavior change
//
//Demerits of State Design Pattern
//
//Overhead of state classes
//If applied to an application with
//small set of states

void StatePattern::examples() {


	// example of execution of the pattern  
	//uncomment and copie the pattern test classes and following test example 
	//in a separate project in order to test it 
//#include <iostream>
//#include <typeinfo>
//
//	using namespace std;
//	/**
//	* The base State class declares functions that all Concrete States should
//	* implement.
//	* It also provides a backreference to the ContextMobile object, associated
//	* with the State.
//	* This backreference can be used by States to transition the ContextMobile
//	* to another State.
//	*/
//	class ContextMobile;
//	class State {
//	protected:
//		ContextMobile* contextMobile;
//	public:
//		void setContext(ContextMobile* cxtMob) {
//			this->contextMobile = cxtMob;
//		}
//		virtual ~State() {}
//		virtual void playRingtone() = 0;
//		virtual void toggleSilentMode() = 0;
//
//	};
//
//	/**
//	* The ContextMobile defines the interface of interest to clients. It also maintains a
//	* reference to an instance of a State subclass, which represents the current
//	* state of the ContextMobile.
//	*/
//	class ContextMobile {
//		State* currentState;
//	public:
//		ContextMobile(State* st) :currentState(nullptr) {
//			this->changeState(st);
//		}
//		~ContextMobile() {
//			delete currentState;
//		}
//		/**
//		* The ContextMobile allows changing the State object at runtime.
//		*/
//		void changeState(State* st) {
//			cout << "Context: Transition to " << typeid(*st).name() << ".\n";
//			if (currentState != nullptr)
//				delete this->currentState;
//			this->currentState = st;
//			this->currentState->setContext(this);
//		}
//
//		/**
//		 * The ContextMobile delegates part of its behavior to the current State object.
//		 */
//		void playRingtone()
//		{
//			this->currentState->playRingtone();
//		}
//		void toggleSilentMode() {
//			this->currentState->toggleSilentMode();
//		}
//	};
//
//	/**
//	* ConcreteStateSilent and ConcreteStateSwitchedOn are the Concrete States
//	* that implement various behaviors, associated with a state of the
//	* ContextMobile.
//	*/
//	class StateSilent : public State {
//	public:
//		void playRingtone() {
//			cout << "silentmode activated , no sound \n";
//		}
//
//		void toggleSilentMode();
//
//	};
//
//	class StateSwitchedOn : public State {
//	public:
//		void playRingtone() {
//			cout << "mobile playing ringtone ,,;;,,:: \n";
//		}
//		void toggleSilentMode() {
//			this->contextMobile->changeState(new StateSilent);
//		}
//	};
//
//	void StateSilent::toggleSilentMode()
//	{
//		this->contextMobile->changeState(new StateSwitchedOn);
//	}
//
//	int main() {
//
//		ContextMobile* mobile = new ContextMobile(new StateSwitchedOn);
//		mobile->playRingtone();
//		mobile->toggleSilentMode();
//		mobile->playRingtone();
//		delete mobile;
//		return 0;
//	}

}

void StatePattern::execute() {
	std::map<int, int> limits = { {5, 51},{54, 160} };
	Context::execute(limits, "StatePattern.cpp");
}