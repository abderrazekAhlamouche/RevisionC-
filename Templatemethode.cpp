#include "TemplateMethode.h"
using namespace std;

	//Important Notes
//Club common behavior in template class
//Differences are implemented in subclasses
//
//Super class to contain skeleton
//of an algorithm, sub classes to
//define specific steps without
//changing algorithm’s structure
//
//steps:
//
//Analyze algorithm
//Break into steps
//
//Create abstract base class
//Declare template method
//
//Divide abstract class
//Compulsory stepsand optional steps
//
//Add required hooks
//Specific to an object
//
//Create new concrete class
//For each variation
//
//Merits of Template Method Pattern
//Large algorithms Unaffected
//Duplicate code Pulls down
//Variations Can’t affect algorithm
//
//Demerits of Template Method Pattern
//Limited to skeletonClients have limited scope
//
//Steps to follow
//Difficult to follow steps to follow
//
//Difficult to maintain
//If algorithm to be maintained is large

void TemplateMethode::examples() {

	//example of the pattern

    /**
 * This is an abstract class that defines the skeleton
 * of the algorithms that the concrete classes can inherit
 */
    class FruitDrink {
    public:
        // Template function
        void prepareFruitDrink() {
            peel();
            cutInPieces();
            addToMixerGrinder();
            addCondiments();
            startMixerGrinder();
            stopMixerGrinder();
        }

        virtual ~FruitDrink() {}
    protected:
        // Compulsory functions
        virtual void peel() const = 0;
        virtual void cutInPieces() const = 0;
        virtual void addToMixerGrinder() const = 0;
        virtual void startMixerGrinder() const = 0;
        virtual void stopMixerGrinder() const = 0;

        // Optional hook function
        virtual void addCondiments() const {};
    };

    /**
     * Concrete classes inheriting abstract class FruitDrink
     * They will all the compulsory functions (pure virtual)
     * as well as the optional hook functions
     */
    class OrangeJuice : public FruitDrink {
    protected:
        void peel() const {
            cout << "Peeling orange\n";
        }

        void cutInPieces() const {
            cout << "Cutting orange in pieces\n";
        }

        void addToMixerGrinder() const {
            cout << "Adding orange pieces to mixer grinder\n";
        }

        void startMixerGrinder() const {
            cout << "Starting mixer grinder\n";
        }

        void stopMixerGrinder() const {
            cout << "Stopping mixer grinder\n";
        }
    };

    class BananaMilkShake : public FruitDrink {
    protected:

        void peel() const {
            cout << "Peeling banana\n";
        }

        void cutInPieces() const {
            cout << "Cutting banana in pieces\n";
        }

        void addToMixerGrinder() const {
            cout << "Adding banana pieces to mixer grinder\n";
        }

        void addCondiments() const {
            cout << "Adding milk and sugar\n";
        }

        void startMixerGrinder() const {
            cout << "Starting mixer grinder\n";
        }

        void stopMixerGrinder() const {
            cout << "Stopping mixer grinder\n";
        }
    };

    FruitDrink* objFruitDrink = new OrangeJuice();
    objFruitDrink->prepareFruitDrink();
    delete objFruitDrink;

    cout << "\n";

    objFruitDrink = new BananaMilkShake();
    objFruitDrink->prepareFruitDrink();
    delete objFruitDrink;

}
void TemplateMethode::execute() {
	std::map<int, int> limits = { {3, 43},{45, 142} };
	Context::execute(limits, "Templatemethode.cpp");
}