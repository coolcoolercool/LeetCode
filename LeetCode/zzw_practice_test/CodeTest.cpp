#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	string publicMethod() {
		cout << "public" << endl;
		return "public";
	};
};

int main_lmkjh() {
	Solution solu;
	solu.publicMethod();

	return 0;
};