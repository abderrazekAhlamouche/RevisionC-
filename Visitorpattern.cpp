#include"Visitorpattern.h"
using namespace std; 

       //Important Note
//Separate visitor class
//Get information without disturbing objects
//
//Separate algorithms from the
//objects that they operate on
//
//Problem Statement
//Composites of objects
//Client asks for additional feature
//Feature affects all the objects
//Change is difficult for a huge number of objects
//Risky for application stability
//Be ready for some more features!
//
//How Visitor Pattern Addresses It
//Place new behavior into a separate class called Visitor
//The client knows how to traverse object structure
//Original object is passed as an argument to visitor class function
//
//steps!
//Declare Visitor interface
//Visiting functions
//
//Declare element interface
//Acceptance functions
//
//Implement acceptance functions
//In concrete element classes
//
//Work with visitors
//Via visitors interface
//
//Create concrete visitor class
//For each behavior that can’t be implemented inside the element
//hierarchy
//
//Client to create visitor objects
//Pass them to accept function of elements
//
//Merits of Visitor Pattern
//
//Add new behavior
//Can work with different classes
//
//Collect useful info
//Work with different objects
//
//Multiple versions
//Same behavior in the same class
//
//Demerits of Visitor Pattern
//Need to update all the visitors
//Any new behavior addition requires updating all the visitors
//
//Visitors may lack access
//Visitors may lack access to private fields of the component classes


void Visitorpattern::examples(){
	
	//execution example

    MobileComponent* mobilePhones[] = { new BasicPhone(2000, 2), new SmartPhone(4000, 6) };
    MobileVisitorImpl* visitor = new MobileVisitorImpl;

    for (int i = 0; i < 2; i++) {
        mobilePhones[i]->accept(visitor);
        cout << "\n";
    }

    delete visitor;

}
void Visitorpattern::execute() {
	std::map<int, int> limits = { {8, 50},{51, 110} };
    std::map<int, int> limits2 = { {3, 61},{64, 76} };
	Context::execute(limits, "Visitorpattern.h");
    Context::execute(limits2, "Visitorpattern.cpp");
}