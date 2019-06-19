#include <iostream>
using namespace std;

class Date
{
public:
	bool LeapYear(int year)
	{
		if (year % 4 == 0 && year != 100 || year % 400 == 0)
			return true;
		else
			return false;
	}

	int GetMonthDay(int year, int month)//求每个月的天数
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && LeapYear(year))
		{
			return 29;
		}
		return monthArray[month];
	}

	Date(int year = 2019, int month = 1, int day = 1) //构造函数
	{
		//判断日期是否合法
		if (year >= 0 && month>0 && month<13 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合法" << endl;
		}
	}

	Date(const Date&d) //拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date& operator=(const Date& d)//赋值重载
	{
		//自己不能给自己赋值
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator+=(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	Date operator-=(int days)
	{
		_day -= days;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
				
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	Date operator+(int days)
	{
		*this += days;
		return *this;
	}

	Date operator-(int days)
	{
		*this -= days;
		return *this;
	}

	int operator-(const Date& d);

	//++d  前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	//d++  后置++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	//--d  前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	//d--  后置--
	Date operator--(int)
	{
		Date ret = (*this);
		*this -= 1;
		return ret;
	}

	bool operator>(const Date& d)const
	{
		return _year > d._year
		||(_year == d._year && _month > d._month)
		||(_year == d._year) && (_month == d._month) && (_day > d._day);
	}

	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		
	}

private:
	int _year;
	int _month;
	int _day;

};

void test1()
{
	Date d1(2019, 1, 1);
	d1.Print();
	d1 += 1000;
	//d1 -= 1000;
	d1.Print();

    //d1--;
	//--d1;
	//d1.Print();
}

void test2()
{
	Date d1(2019, 1, 1);
	Date d2(2019, 1, 1);

}
int main()
{
	test1();
	//test2();
	system("pause");
	return 0;
}