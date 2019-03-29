#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution{
	public:
	int Sum_Solution (int n) {
		int back = n;
		back && (back += Sum_Solution (n - 1));
		return back;
	}
};

int main () {
	Solution a;
	cout << a.Sum_Solution (10) << endl;
	system ("pause");
	return 0;
}