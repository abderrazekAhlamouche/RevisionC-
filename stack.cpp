#include"stack.h"
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>

using namespace std;

template <typename T>
void report_stack(T& stk) {
	cout << "size: " << stk.size() << " top: " << stk.top() << endl;
}




void Stack::examples() {
	
	//Stack examples 

    // vector
     message("stk1");
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    stack<int, vector<int>> stk1(v1);
    report_stack(stk1);
    message("stk1 push 42");
    stk1.push(42);
    report_stack(stk1);
    message("stk1 pop");
    stk1.pop();
    report_stack(stk1);

    message("stk2 default stack (deque)");
    stack<string> stk2;
    for (string s : {"one", "two", "three", "four", "five"}) {
        stk2.push(s);
    }
    report_stack(stk2);
    message("stk2 push forty-two");
    stk2.push("forty-two");
    report_stack(stk2);
    message("stk2 pop");
    stk2.pop();
    report_stack(stk2);

}

void Stack::execute()
{
	std::map<int, int> limits = { {20, 33},{34, 47} };
	Context::execute(limits, "stack.cpp");
}