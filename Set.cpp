#include"set.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

// print the elements of the set
template<typename T>
void print_set(T& s) {
    if (s.empty()) return;
    for (auto x : s) cout << x << " ";
    cout << endl;
}

// print a simple message
void msgset(const char* m) { cout << m << endl; }
template <typename T>
void msgset(const char* m, const T& v) { cout << m << ": " << v << endl; }

void Set::examples() {

        //Set examples 

    msgset("construct set set1");
    set<string> set1 = { "one", "two", "three", "four", "five" };
    msgset("size of set", set1.size());
    msgset("ordered set is alphabetical");
    print_set(set1);

    msgset("insert element six");
    set1.insert("six");
    print_set(set1);

    msgset("find and erase element six");
    set<string>::iterator it = set1.find("six");
    if (it != set1.end()) {
        msgset("erasing", *it);
        set1.erase(it);
    }
    else {
        cout << "not found" << endl;
    }
    print_set(set1);

    msgset("inserting duplicate element five");
    set1.insert("five");
    print_set(set1);
    cout << endl;


    msgset("construct unordered set set1");
    unordered_set<string> set2 = { "one", "two", "three", "four", "five" };
    msgset("size of set", set2.size());
    msgset("unordered set has no defined order");
    print_set(set2);

    msgset("insert element six");
    set2.insert("six");
    print_set(set2);

    msgset("find and erase element six");
    auto it2 = set2.find("six");
    if (it2 != set2.end()) {
        msgset("erasing", *it2);
        set2.erase(it2);
    }
    else {
        cout << "not found" << endl;
    }
    print_set(set2);

    msgset("inserting duplicate element five");
    set2.insert("five");
    print_set(set2);
    cout << endl;
}

void Set::execute()
{
	std::map<int, int> limits = { {22, 50},{51, 76} };
	Context::execute(limits, "Set.cpp");
}