#pragma once
#include <iostream>
#include <typeinfo>

using namespace std;
/**
* The base State class declares functions that all Concrete States should
* implement.
* It also provides a backreference to the ContextMobile object, associated
* with the State.
* This backreference can be used by States to transition the ContextMobile
* to another State.
*/
class ContextMobile;
class State {
protected:
	ContextMobile* contextMobile;
public:
	void setContext(ContextMobile* cxtMob) {
		this->contextMobile = cxtMob;
	}
	virtual ~State() {}
	virtual void playRingtone() = 0;
	virtual void toggleSilentMode() = 0;

};

/**
* The ContextMobile defines the interface of interest to clients. It also maintains a
* reference to an instance of a State subclass, which represents the current
* state of the ContextMobile.
*/
class ContextMobile {
	State* currentState;
public:
	ContextMobile(State* st) :currentState(nullptr) {
		this->changeState(st);
	}
	~ContextMobile() {
		delete currentState;
	}
	/**
	* The ContextMobile allows changing the State object at runtime.
	*/
	void changeState(State* st) {
		cout << "Context: Transition to " << typeid(*st).name() << ".\n";
		if (currentState != nullptr)
			delete this->currentState;
		this->currentState = st;
		this->currentState->setContext(this);
	}

	/**
	 * The ContextMobile delegates part of its behavior to the current State object.
	 */
	void playRingtone()
	{
		this->currentState->playRingtone();
	}
	void toggleSilentMode() {
		this->currentState->toggleSilentMode();
	}
};

/**
* ConcreteStateSilent and ConcreteStateSwitchedOn are the Concrete States
* that implement various behaviors, associated with a state of the
* ContextMobile.
*/
class StateSilent : public State {
public:
	void playRingtone() {
		cout << "silentmode activated , no sound \n";
	}

	void toggleSilentMode();

};

class StateSwitchedOn : public State {
public:
	void playRingtone() {
		cout << "mobile playing ringtone ,,;;,,:: \n";
	}
	void toggleSilentMode() {
		this->contextMobile->changeState(new StateSilent);
	}
};

void StateSilent::toggleSilentMode()
{
	this->contextMobile->changeState(new StateSwitchedOn);
}
