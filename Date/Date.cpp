//#include "Date.h"

//bool LeapYear(int year)
//{
//	if (year % 4 == 0 && year != 100 || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//
//int GetMonthDay(int year, int month)//求每个月的天数
//{
//	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && LeapYear(year))
//	{
//		return 29;
//	}
//	return monthArray[month];
//}
//
//Date::Date(int year, int month, int day)//构造函数
//{
//	//判断日期是否合法
//	if (year >= 0 && month>0 && month<13 && day <= GetMonthDay(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "日期不合法" << endl;
//	}
//}
//
//void test1()
//{
//	Date d1(2019, 10, 14);
//	d1.Print;
//}
//
//void Date::Print()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//Date::Date(const Date& d)  //拷贝构造函数
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
