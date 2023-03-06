#include"Obsever.h"
#include "list.h"
#include<memory>
using namespace std; 

	//Important Notes
//Define one to many dependency, get notified on the change of state
//Objects Interested in Events of One Object
//
//How Observer Pattern Addresses It
//
//Subject / Publisher
//Generates events ofinterest and notifies observers
//
//Observer
//Interested in events and subscribes or unsubscribes
//
//Subscribe
//Observers subscribe or unsubscribe for events
//
//Improvements Brought by Observer Pattern
//Introduce new subscriber
//Reuse subscriber subject
//Establish relation run time
//Subscribe silently
//
//Demerits of Observer Design Pattern
//
//Random Notifications
//Observers are notified in random fashion
//
//Memory Leak
//Explicit register and unregister of observers


void Observer::examples(){

	//example of observer pattern 
	
	// This is an interface class for Customer (Observer) class
	class ObjObserver {
	public:
		virtual ~ObjObserver() {};
		virtual void update(const string& message_from_subject) = 0;
	};

	// This is an interface class for GroceryStore (Subject/Publisher) class
	class Subject {
	public:
		virtual ~Subject() {};
		virtual void subscribe(ObjObserver* observer) = 0;
		virtual void unsubscribe(ObjObserver* observer) = 0;
		virtual void notify(string msg) = 0;
	};

	class Store : public Subject{
	private:
		list<ObjObserver*> watchers; 
	public:
		map<string, bool> storeItem;
		Store(map<string, bool> items) :storeItem(items) {};
		virtual ~Store() { cout << "store destroyed \n"; }
		void subscribe(ObjObserver* obs) { watchers.push_back(obs); }
		void unsubscribe(ObjObserver* obs) { watchers.remove(obs); }
		void notify(string msg ){
			for (auto obs : watchers)
			{
				obs->update(msg);
			}
		}
		void refillStoreItems(pair<string, bool> item) {
			if(storeItem.find(item.first) == storeItem.end())
			{ 
				storeItem.insert(item);
			}
			else {
				if (storeItem[item.first] != item.second)
				{
					storeItem[item.first] = item.second;
					string state = item.second ? " available" : " unavailable";
					notify("new update for item " + item.first +" " + state);
				}
					
			}
		}
	};

	class client : public ObjObserver{
		Store &store; 
	public:
		client(Store& st) :store(st) {
			this->store.subscribe(this);
		}
		virtual ~client() { cout << "clent dissapeared \n"; }
		void update(const string& msg) { cout << "new notif receved " + msg + "\n"; }
		void unsubscribeCustomer() {
			cout << "client wants to unsubscribe from store\n";
			store.unsubscribe(this);
		}
		bool purchaseItem(string itemName) {
			cout << "Customer wants to purchase item " << itemName << " - ";
			if((store.storeItem.find(itemName)!=store.storeItem.end())&&(store.storeItem[itemName]))
			{ 
				cout << "Item " << itemName << " is available\n";
				return true;
			}
			else {
				cout << "The item " << itemName << " is not available in the Grocery Store\n";
				return false;
			}
		}
	};

	//testing the pattern 

	map<string,bool> itemsExp = { {"Flour", true}, {"Rice", true}, {"Brown Bread", false}, 
							  {"Blueberry Syrup", false}, {"Detergent", true} };

	Store *storeExp = new Store(itemsExp);
	client *clientExp = new client(*storeExp);
	//Store storeExp(itemsExp);
	//client clientExp(storeExp);
	clientExp->purchaseItem("Detergent");
	clientExp->purchaseItem("Flour");
	clientExp->purchaseItem("Rice");
	clientExp->purchaseItem("Brown Bread");
	clientExp->purchaseItem("Blueberry Syrup");
	clientExp->unsubscribeCustomer();
	storeExp->refillStoreItems({ "Blueberry Syrup", true });
	storeExp->refillStoreItems({ "Blueberry Syrup", false });
	delete storeExp;
	delete clientExp;

}
void Observer::execute() {
	std::map<int, int> limits = { {5, 34},{37, 133} };
	Context::execute(limits, "Observer.cpp");
}