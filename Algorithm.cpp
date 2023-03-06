 #include"Algorithm.h"
#include<algorithm>
#include <random>
using namespace std; 
		//Important Notes


template <typename T>
void disp_v(const T& v) {
	if (!v.size()) return;
	for (auto e : v) { cout << e << " "; }
	cout << endl;
}


template <typename T>
const bool is_prime(const T& num) {
	if (num <= 1) return false;
	bool primeflag = true;
	for (T l = 2; l < num; ++l) {
		if (num % l == 0) {
			primeflag = false;
			break;
		}
	}
	return primeflag;
}

template <typename T>
bool mycomp(const T& lh, const T& rh) {
	return int(lh) < int(rh);
}

void Algorithm::examples()
{
	//binary search example 
	{

		vector<int> v1 = { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79 };
		//print v1 
		disp_v(v1);

		//Warning : before the binary search we must sort the container 
		sort(v1.begin(), v1.end());
		//display v1 sorted 
		disp_v(v1);

		//excuting binary search 
		if (binary_search(v1.begin(), v1.end(), 31))
		{
			cout << "31 found \n";
		}
		else {
			cout << "31 not found \n";
		}

		//conditional all_of 
		{
			const vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
			disp_v(v1);

			if (all_of(v1.begin(), v1.end(), is_prime<int>))
			{
				cout << "all vector elements is prime \n";
			}
			else {
				cout << "not all vector elements is prime \n";

			}
		}

	}

	//Conditional all_of using Lambda 

	{
		const vector<int> v1 = { 2, 3, 5, 7, 11,14, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		disp_v(v1);

		if (all_of(v1.begin(), v1.end(), [](int n) {
			if (n <= 1) return false;
			bool primeflag = true;
			for (int l = 2; l < n; ++l) {
				if (n % l == 0) {
					primeflag = false;
					break;
				}
			}
			return primeflag;
			}))
		{
			cout << "all vector elements is prime \n";
		}
		else {
			cout << "not all vector elements is prime \n";

		}
	}

	//Copy examples 

	{
		vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		vector<int> v2(v1.size(), 5);
		disp_v(v1);
		disp_v(v2);
		//Warning : a runtime error will occure if the size of the the two vectors are not the same 
		copy(v1.begin(), v1.end(), v2.begin());
		//v1 copied to v2 
		disp_v(v2);

	}

	//partitions examples 

	{
		vector<int> v1 = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		disp_v(v1);
		//thius will create a partition of the satisfied condition (lambda) in the begenning of the vector 
		partition(v1.begin(), v1.end(), [](int n) {
			if (n < 10) return false;
			return ((n / 10) % 2) == 0;
			});
		cout << "partitions examples " << endl; 
		disp_v(v1);
	}


	//randomize examples 

	{
		vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		disp_v(v1);

		random_device rd;
		mt19937 g(rd());

		shuffle(v1.begin(), v1.end(), g);
		cout << "randomize examples  " << endl;
		disp_v(v1);
		
	}

	//replace examples 

	{
		vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,47,47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		disp_v(v1);
		//replace 47 by 99 
		replace(v1.begin(), v1.end(), 47, 99);
		cout << "replace examples  " << endl;
		disp_v(v1);
		
	}

	//find examples 

	{
		const vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		disp_v(v1);

		auto it = find(v1.begin(), v1.end(), 41);
		cout << "find examples   " << endl;
		if (it != v1.end()) {
			size_t index = it - v1.begin();
			cout << "found at index " << index << ": " << *it << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}


	//sort examples 

	{
		vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
		vector<double> v2 = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
		disp_v(v1);
		disp_v(v2);
		//normal sort 
		sort(v1.begin(), v1.end());
		cout << "sort examples    " << endl;
		disp_v(v1);
	}

	//stable_sort examples 
	{
		vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
		vector<double> v2 = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
		disp_v(v2);

		vector<double> v3;

		v3 = v2;
		cout << "stable_sort examples    " << endl;
		////With stable_sort, it is ensured that you always will get the first result. With the duplicates in the same order they were in the initial list.
		sort(v3.begin(), v3.end(), [](int n, int m) {return int(n) < int(m); });
		disp_v(v3);

		v3 = v2;
		stable_sort(v3.begin(), v3.end(), [](float n, float m) {return n < m; });
		disp_v(v3);

	/*	v3 = v2;
		sort(v3.begin(), v3.end(), mycomp<double>);
		disp_v(v3);

		v3 = v2;
		stable_sort(v3.begin(), v3.end(), mycomp<double>);
		disp_v(v3);*/
	}
}

void Algorithm::execute()
{
	std::map<int, int> limits = { {27, 51},{52, 204} };
	Context::execute(limits, "Algorithm.cpp");
}