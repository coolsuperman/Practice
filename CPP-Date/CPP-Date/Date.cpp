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
		this->_day += day;
		if ( this->_day > this->getCipacaty (this->_year , this->_month) ) {
			int Cipacaty = this->getCipacaty (this->_year , this->_month);
			int count = this->_day / Cipacaty;
			this->_day -= Cipacaty*count;
		}
		if ( this->_month > 12 ) {
			int count = this->_month / 12;
			this->_year += count;
			this->_month -= 12 * count;
		}
		return *this;
	}
	Date operator-=(int day) {
		this->_day -= day;
		if ( this->_day <1 ) {
			int Cipacaty = this->getCipacaty (this->_year , this->_month);
			int count = this->_day / Cipacaty - 1;//负数
			this->_month += count;
			this->_day -= Cipacaty*count;
		}
		if ( this->_month < 1 ) {
			int count = this->_month / 12 - 1;//负数
			this->_year += count;
			this->_month -= 12 * count;
		}
		return *this;
	}
	Date operator+(int days){
		*this += days;
	}
	Date operator-(int days) {
		*this -= days;
	}
	
	int operator-(const Date& d) {//两个Date互减,考虑润年
		int small = 0 , big = 0,add = 0,small_month,big_month;
		if ( this->_year < d._year ) {
			small = this->_year;
			big = d._year;
		}
		else {
		    big = this->_year;
			small = d._year;
		}
		for ( int i = small + 1; i < big; i++ ) {
			if ( (i % 4 == 0 && i % 10 != 0) || (i % 400 == 0) ) {
				 add++;
			}
		}
		int this_days = 0 , d_days = 0;
		for ( int i = 1; i < this->_month; i++ ) {
			this_days += this->getCipacaty (this->_year , i);
		}
		this_days += this->_day;
		for ( int i = 1; i < d._month; i++ ) {
			d_days += d.getCipacaty(d._year , i);
		}
		d_days += d._day;
		
	}
	Date& operator++() {
		*this += 1;
		return *this;
	}
	Date operator++(int) {
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
		if ( this->_year > d._year ) { return true; }
		else if(this->_year < d._year) { return false; }
		else {
			if ( this->_month > d._month ) { return true; }
			else if ( this->_month< d._month ) { return false; }
			else {
				if ( this->_day > d._day ) { return true; }
				else { return false; }
			}
		}
	}
	bool operator==(const Date& d)const {
		if ( this->_year == d._year ) {
			if ( this->_month == d._month ) {
				if ( this->_day == d._day ) { return true; }
			}
		}
		return false;
	}
	bool operator<(const Date& d)const {
	}
	bool operator>=(const Date& d)const {
		if ( *this > d || *this == d ) { return true; }
		else {
			return false;
		}
	}
	bool operator<=(const Date& d)const;
	bool operator!=(const Date& d)const;
	private:
	int _year;
	int _month;
	int _day;
};


int main () {
	system ("pause");
	return 0;
}