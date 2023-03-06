#include"Pair.h"
#include <iostream>
#include <utility>
#include <string>
using namespace std;

// print the pair
template<typename T1, typename T2>
void printpair(pair<T1, T2>& p) {
	cout << p.first << " : " << p.second << endl;
}




void Pair::examples() {

	//pair examples 

    // initializer list
    cout <<"initializer list\n";
    pair<int, string> p1 = { 47, "seven" };
    printpair(p1);

    // default constructor
    cout <<"default constructor\n";
    pair<int, string> p2(72, "seventy");
    printpair(p2);

    // from make_pair
    cout <<"make_pair\n";
    pair<int, string> p3;
    p3 = make_pair(7, "seven");
    printpair(p3);

    // comparison operators
    cout << "p1 == p2 " << (p1 == p2) << endl;
    cout << "p1 < p2 " << (p1 < p2) << endl;
    cout << "p1 < p3 " << (p1 < p3) << endl;
    cout << "p1 > p2 " << (p1 > p2) << endl;
    cout << "p2 > p3 " << (p2 > p3) << endl;
}

void Pair::execute()
{
	std::map<int, int> limits = { {19, 31},{31, 44} };
	Context::execute(limits, "pair.cpp");
}