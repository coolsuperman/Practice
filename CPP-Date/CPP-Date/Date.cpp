//丰富完善Date类的各种功能
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Date {
	public:
	int getCipacaty (int year , int month) {
		int days [13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
		int day = days [month];
		if ( month == 2 ) {
			if ( (year % 4 == 0 && year % 10 != 0) || (year % 400 == 0) ) {
				day += 1;
			}
		}
		return day;
	}
	Date (int year = 1900 , int month = 1 , int day = 1) {//这是全缺省构造函数；
		if ( year <= 0 || month > 12 || month<1 || day <= 0 || day>getCipacaty (year , month) ) {
			std::cout << "非法日期,日期已设置1900-1-1" << std::endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	Date (const Date& d) {//这是拷贝构造函数；
		_year = d._year;//因为此处参数是d的引用，所以使用.访问成员变量；
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d){//之后清一色的运算符重载
		if ( this != &d ) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+=(int day) {
		if ( day < 0 ) {//考虑小于零；
			return *this -= -day;
		}
		_day += day;
		while ( _day > getCipacaty (_year ,_month) ) {
			_day -= getCipacaty (_year , _month);
			++_month;
			if ( _month == 13 ) {
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date operator-=(int day) {
		if ( day < 0 ) {
			return *this += -day;
		}
		_day -= day;
		while ( _day <=0 ) {
			_day += getCipacaty (_year , _month);
			--_month;
			if ( _month == 0 ) {
				_month = 12;
				--_year;
			}
		}
		return *this;
	}
	Date operator+(int days){
		Date ret (*this);//不能改变原来的值，所以先拷贝一份
		ret += days;
		return ret;
	}
	Date operator-(int days) {
		Date ret (*this);//不能改变原来的值，所以先拷贝一份
		ret -= days;
		return ret;
	}
	
	int operator-(const Date& d) {//两个Date互减,考虑润年
		Date c (*this);//因为是const，所以拷贝一下
		int flag = 1;
		if ( c < d ) { flag = -1; }
		int day = 0;
		if ( c < d ) {
			while ( c < d ) {
				++c;
				++day;
			}
			
		}
		else {
			while ( c > d ) {
				--c;
				++day;
			}
		}
		return day*flag;
	}
	Date& operator++() {//前置++；
		*this += 1;
		return *this;
	}
	Date operator++(int) {//后置++；
		Date tmp (*this);
		*this += 1;
		return tmp;
	}
	Date& operator--() {
		*this -= 1;
		return *this;
	}
	Date operator--(int) {
		Date tmp (*this);
		*this += 1;
		return tmp;
	}
	bool operator>(const Date& d)const {
		if ( _year > d._year ) { return true; }
		else if(_year < d._year) { return false; }
		else {
			if ( _month > d._month ) { return true; }
			else if (_month< d._month ) { return false; }
			else {
				if ( _day > d._day ) { return true; }
				else { return false; }
			}
		}
	}
	bool operator==(const Date& d)const {
		if ( _year == d._year ) {
			if ( _month == d._month ) {
				if ( _day == d._day ) { return true; }
			}
		}
		return false;
	}
	bool operator<(const Date& d)const {
		if ((*this != d) && (!(*this>d))) {
			return true;
		}
		return false;
	}
	bool operator>=(const Date& d)const {
		if ( *this > d || *this == d ) { return true; }
		else {
			return false;
		}
	}
	bool operator<=(const Date& d)const {
		if ( *this < d || *this == d ) { return true; }
		else {
			return false;
		}
	}
	bool operator!=(const Date& d)const {
		if ( !(*this == d) ) {
			return true;
		}
		return false;
	}
	void display () {
		std::cout << _year<<"-" << _month<<"-"<<_day<<std::endl;
	}
	private:
	int _year;
	int _month;
	int _day;
};


int main () {
	Date d1 (1998 , 5,27);
	Date d2 (2019 , 03 , 27);
	d1.display();
	std::cout << "—" << std::endl;
	d2.display ();
	std::cout << "="<<d2 - d1 << std::endl;
	system ("pause");
	return 0;
}