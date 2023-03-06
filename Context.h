#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<map>
class PrintCode {
	int m_firstLimit;
	int m_secondLimit;
	const std::string filename; 

public:
	PrintCode(int flimit, int slimit, const std::string fname);

     std::vector<std::string> filterCode(std::vector<std::string>& v);
public: 
	  std::vector<std::string> getCode(const int& firstLimit, const int& secondlimit, const std::string& fileName);
	 
	  void displayCode(); 
};

class Context {

public:
	void displaySource(int, int, std::string const&)const;
	virtual void execute(std::map<int, int>&, std::string filename);
	virtual void examples() = 0;
	//template<typename T>
 //   static void output(std::string const& msg, T* tab, int dim = 0);
};

