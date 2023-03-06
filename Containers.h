#pragma once
#include"Context.h"
#include<vector>
#include<array>
#include<list>

class Containers : public Context {

public:
	void execute();
	void examples();
	template <typename T>
	void message(const char* m, const T& v);
	void message(const char* s); 
	void message(const char* s, const int n); 
};