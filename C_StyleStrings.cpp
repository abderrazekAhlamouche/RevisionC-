#include"C_StyleStrings.h"
#include"C_StyleArrays.h"


		//Important Notes


//An array of char elements 

//ends with null character \0 (ascii value =0)

//large functions with names starts with str 

//#include<cstring>

//Warning:forget to include room for the null character 

//can build std::string from one 

//std::string has a member c_str() to have one 




void C_StyleStrings::examples()
{


		//C strings example

	//declare string 
	char const* s1 = "hello ";
	int i = strlen(s1);
	//display s1
	std::cout << "s1= " << s1 << "\n";
	//display length of s1 
	std::cout <<"s1 length = "<<i<<"\n";

	//create dynamic array 
	//Warning: concat s2 with " abderrazek" will maje us write the 
	//Warning:the null caracter into someone else memory 
	//Warning:this will compile but cause runtime memory issues 
	//char* s2 = new char[strlen(s1) + strlen(" abderrazek")];

	//this one is correct 
	char* s2 = new char[strlen(s1) + strlen(" abderrazek")+1];
	//display size of s2
	int test = strlen(s2);
	std::cout <<"length s2 = " <<test <<"\n";
	//copy s1 into s2 
	strcpy(s2, s1);

	//display s2 
	std::cout <<"s2 = "<< s2 <<"\n";

	//concatenate operation
	strcat(s2, " abderrazek");

	//display s2 after concat
	std::cout << "concat s2 = " << s2 << "\n";

	//initialise string 
	char hello[] = {' ','w','o','r','l','d'};

	//Warning : because the is no null caracter at the end of string hello 
	//Warning : the strlen function won't give us the correct value 

	//int size = strlen(hello);

	//display the size 
	//std::cout<<"size of hello : "<<size<<"\n";

	//better initialise using "" exp : char str[]="better"

	//initialize std::string from c tyle string 
	std::string s(s1);

	//display s 
	std::cout<<"s ="<<s<<"\n";

	//create dynamic c string
	char* s3 = new char[s.length() + 1];

	//copy s to s3 
	strcpy(s3,s.c_str());

	//display s3 
	std::cout <<"s3 = "<< s3<<"\n";

	//Warning :need to delet dynamic strings otherwise memory leak 
	delete[] s2;
	delete[] s3;

}

void C_StyleStrings::execute() {
	std::map<int, int> limits = { {3, 21},{28, 93} };
	Context::execute(limits, "C_StyleStrings.cpp");
}