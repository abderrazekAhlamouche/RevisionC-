#include"IteratorPattern.h"

#include <vector>
using namespace std;

class NumberIterator {
public:
    virtual ~NumberIterator() {};
    virtual int next() = 0;
    virtual bool isFinished() = 0;
};

class ForwardsIterator : public NumberIterator {
    int currentPosition;
    std::vector<int>& numbers;
public:
    ForwardsIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(currentPosition);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

class BackwardsIterator : public NumberIterator {
    int currentPosition;
    std::vector<int>& numbers;
public:
    BackwardsIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(numbers.size() - currentPosition - 1);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

void IteratorPattern::examples() {

    vector<int> v = { 2,3,4,5,6,7,8,9 };
    ForwardsIterator* fw = new ForwardsIterator(v);
    BackwardsIterator* bw = new BackwardsIterator(v);
    cout << "first 3 element of V : " << fw->next() << endl;
    cout << "last 3 element of V : " << bw->next() << endl;
    delete fw;
    delete bw;
}

void IteratorPattern::execute() {
	std::map<int, int> limits = { {5, 42},{44, 50} };
	Context::execute(limits, "IteratorPattern.cpp");
}