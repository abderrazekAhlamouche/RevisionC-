#include"tuple.h"
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

// print the elements of the tuple
template<typename T>
void print3tuple(T t) {
    auto tsz = tuple_size<decltype(t)>::value;
    if (tsz != 3) return;
    cout << get<0>(t) << " : " << get<1>(t) << " : " << get<2>(t) << endl;
}



void Tuple::examples() {

    //Tuple examples 

    // initializer list
    cout << "initializer list\n";
    tuple<int, string, int> t1 = { 47, "forty-seven", 1 };
    print3tuple(t1);

    // default constructor
    cout << "default constructor\n";
    tuple<int, string, int> t2(72, "seventy-two", 2);
    print3tuple(t2);

    // make_tuple
    cout << "make_tuple\n";
    auto t3 = make_tuple(7, "seven", 3);
    print3tuple(t3);

    // comparison operators
    cout <<"t1 == t2 "<< (t1 == t2) << endl;
    cout<< "t1 < t2 " <<  (t1 < t2) << endl;
    cout << "t1 < t3 " << (t1 < t3)<< endl ;
    cout << "t1 > t2 " << (t1 > t2) << endl;
    cout << "t2 > t3 "<< (t2 > t3) << endl;

}

void Tuple::execute()
{
	std::map<int, int> limits = { {20, 31},{32, 44} };
	Context::execute(limits, "tuple.cpp");
}