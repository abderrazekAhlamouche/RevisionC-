#include "Context.h"
#include<windows.h>





PrintCode::PrintCode(int flimit, int slimit, const std::string fname) :m_firstLimit(flimit), m_secondLimit(slimit), filename(fname) {}

 std::vector<std::string> PrintCode::getCode(const int& firstLimit, const int& secondlimit, const std::string& fileName)
{
	
	std::vector<std::string> result;
		std::ifstream file(fileName);

		if (!file.is_open())
		{
			std::cout << "Error : cannot open file " << fileName << "\n";
		}
		else {
			int lineNbr = 1;
			do
			{
				std::string TrashStr;
				getline(file, TrashStr);
				lineNbr++;
			} while (lineNbr != firstLimit);

			for (lineNbr; lineNbr <= secondlimit; lineNbr++)
			{
				std::string usefullStr; 
				getline(file, usefullStr);
				result.push_back(usefullStr);
			}
			file.close();
		}
	
	return result; 
}

  std::vector<std::string> PrintCode::filterCode(std::vector<std::string>& v) {
	 for (std::vector<std::string>::iterator iter= v.begin();iter != v.end() ; iter++)
	 {
		 std::size_t found = iter->find("cout");
		 if (found != std::string::npos)
			 v.erase(iter);
	 }
	 return v; 
 }

 void PrintCode::displayCode() {
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	 std::vector<std::string> Vout = getCode(m_firstLimit,m_secondLimit,filename);
	 for (auto out : Vout)
	 {
		 size_t posComment = out.find("//");
		 size_t posRed = out.find("Important");
		 size_t posRed_2= out.find("Examples");
		 size_t posBlue  = out.find("example");
		 size_t posYellow = out.find("Warning");
		
		 if (posComment != std::string::npos)
		 {
			 out.erase(posComment, 2);
		 }
		 if(posRed != std::string::npos)  {
			 SetConsoleTextAttribute(hConsole, 12);	 
		 }else if (posRed_2 != std::string::npos) {
			 SetConsoleTextAttribute(hConsole, 12);
		 }
		 else if (posBlue != std::string::npos) {
			 SetConsoleTextAttribute(hConsole, 9);
		 }
		 else if (posYellow != std::string::npos) {
			 SetConsoleTextAttribute(hConsole, 14);
		 }else if ((posComment != std::string::npos)&&
			 (posRed == std::string::npos)&&
			 (posRed_2 == std::string::npos)&&
			 (posBlue == std::string::npos)&&
			 (posYellow == std::string::npos))
		 {
			 SetConsoleTextAttribute(hConsole, 10);
		 }
		 else {
			 SetConsoleTextAttribute(hConsole, 7);
		 }
		 std::cout << out << "\n";
	 }
	 

 }



 void Context::displaySource(int begin, int end, std::string const& filename)const {
	 PrintCode printCode(begin, end, filename);
	 printCode.displayCode();
 }

 void Context::execute(std::map<int, int>& limits, std::string filename) {
	 for (auto elem : limits)
	 {
		 displaySource(elem.first, elem.second, filename);
	 }
	 std::cout << "\n\nExample execution : \n\n";
	 this->examples();
 }

 //template<typename T>
 //void Context::output(std::string const& msg, T* tab, int dim) {
	// if (dim) {
	//	 std::cout << "\n" + msg;
	//	 for (int i = 0; i < dim; i++)
	//		 std::cout << tab[i] << "\t";
	// }
	// else {
	//	 std::cout << "\n" + msg << *tab;
	// }
 //}