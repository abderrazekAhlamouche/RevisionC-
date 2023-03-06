#include"list.h"
#include <iostream>
#include <list>
using namespace std;

template<typename T>
void printl(list<T>& l) {
    if (l.empty()) return;
    for (T& i : l) cout << i << " ";
    cout << endl;
}



void List::examples() {


        //List examples 

    list<int> l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printl(l1);
    message("size", (int)l1.size());
    message("front", l1.front());
    message("back", l1.back());

    message("push back 47");
    l1.push_back(47);
    printl(l1);

    // need an iterator to insert and erase
    message("insert:");
    list<int>::iterator it1 = l1.begin();
    while ((*++it1 != 5) && (it1 != l1.end()));
    if (it1 != l1.end()) {
        message("insert 112 before 5");
        l1.insert(it1, 112);
    }
    printl(l1);

    // find element value 7
    while ((*++it1 != 7) && (it1 != l1.end()));
    if (it1 != l1.end()) {
        message("erase 7");
        l1.erase(it1);
    }
    printl(l1);

    // remove element value 8
    l1.remove(8);
    message("remove 8");
    printl(l1);

    message("erase 112 to 9");
    auto it2 = it1 = l1.begin();
    while ((*++it1 != 112) && (it1 != l1.end()));
    while ((*++it2 != 9) && (it2 != l1.end()));
    if (it1 != l1.end() && it2 != l1.end()) {
        l1.erase(it1, it2);
        printl(l1);
    }

    cout << endl;
}

void List::execute()
{
	std::map<int, int> limits = { {18, 49},{49, 63} };
	Context::execute(limits, "list.cpp");
}