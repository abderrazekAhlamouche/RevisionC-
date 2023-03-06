#include"array.h"
#include <iostream>
#include <array>
#include <string>
using namespace std;

template<typename T, size_t N>
void printa(array<T, N>& a) {
	for (T& i : a) cout << i << " ";
	cout << endl;
}




void Array::examples() {

	//Array examples

    // initializer list
    cout <<"initializer list\n";
    array<int, 5> a1 = { 1, 2, 3, 4, 5 };
    printa(a1);

    // default constructor
    cout <<"default constructor\n";
    array<string, 5> a2;
    a2 = { "one", "two", "three" };
    printa(a2);

    // check the size
   cout << "size of a1 "<< (int)a1.size() << endl ;
    cout <<"size of a2 "<< (int)a2.size() << endl;

    // access elements
    cout << "a1 element 3 is "<<  a1[3] << "\n";
   cout <<"a2 element 2 is " << a2[2] << "\n";
   cout << "a1 element 3 is " << a1.at(3) << endl;
   cout << "a2 element 2 is "<<  a2.at(2) << endl ;

    // direct access data
    //data returns adress of element index 1 
    int* ip1 = a1.data();
    for (size_t i = 0; i < a1.size(); ++i) {
        cout << "element " << i << " is " << *ip1++ << endl;
    }

    string* ip2 = a2.data();
    for (size_t i = 0; i < a2.size(); ++i) {
        cout << "element " << i << " is " << *ip2++ << endl;
    }

}

void Array::execute()
{
	std::map<int, int> limits = { {20, 40},{41, 55} };
	Context::execute(limits, "Array.cpp");
}