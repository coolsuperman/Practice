#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main () {
	int days [13] = { 0 , 31 , 59 , 90 , 120 , 151 , 181 , 212 , 243 , 273 , 304 , 334 , 365 };
	int year , month , day;
	while ( cin >> year >> month >> day ) {
		int total = days [month - 1] + day;
		if ( month>2 ) {
			if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
				total += 1;
			}
		}
		cout << total << endl;
	}
	system ("pause");
	return 0;
}