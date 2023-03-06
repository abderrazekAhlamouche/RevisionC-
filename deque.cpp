#include"deque.h"
#include <iostream>
#include <deque>
#include <string>
using namespace std;

// report deque info
template <typename T>
void reportdeq(T& d) {
    size_t sz = d.size();
    cout << "size: " << sz;
    if (sz) cout << " front: " << d.front() << " back: " << d.back();
    cout << endl;
}

// print deque
template <typename T>
void printdeq(T& d) {
    if (d.empty()) return;
    for (auto v : d) cout << v << " ";
    cout << endl;
}




void Deque::examples() {

    //Deque examples 

    message("create deque");
    deque<string> d1 = { "one", "two", "three" };

    message("push back values");
    d1.push_back("four");
    d1.push_back("five");

    reportdeq(d1);
    printdeq(d1);

    message("pop from front");
    d1.pop_front();
    printdeq(d1);

    message("pop from back");
    d1.pop_back();
    printdeq(d1);

    message("push front");
    d1.push_front("newfront");
    printdeq(d1);

    message("push back");
    d1.push_back("newback");
    printdeq(d1);

}

void Deque::execute()
{
	std::map<int, int> limits = { {29, 48},{49, 57} };
	Context::execute(limits, "deque.cpp");
}