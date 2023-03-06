#pragma once
#include<string>
#include"Context.h"
class C_StyleArrays : public Context {
public:
	void examples();
	void execute();

	 template<typename T>
	friend void output(std::string const& msg,T* tab, int dim = 0);
};