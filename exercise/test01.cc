#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	//// 1.无参构造函数
	//Date()
	//{}
	// 2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	//Date d1; // 调用无参构造函数
	Date d2(2019, 1, 1); // 调用带参的构造函数

	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	Date d3();
}

//C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语法已经定义好的类型：如int / char...，
//自定义类型就是我们使用class / struct / union自己定义的类型，看看下面的程序，就会发现
//编译器生成默认的构造函数会对自定类型成员_t调用的它的默认成员函数

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	return 0;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};


class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

class Date
{
public:
	void Display() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

class Date
{
public:
	void Display(const Date* this)
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
	int _b;
};
class A
{
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	// 非静态成员变量，可以在成员声明时，直接初始化。
	int a = 10;
	B b = 20;
	int* p = (int*)malloc(4);
	static int n;
};
int A::n = 10;
int main()
{
	A a;
	a.Print();
	return 0;
}

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

class Date
{
public:
	Date(int year)
		:_year(year)
	{}
		explicit Date(int year)
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1(2018);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2019;
}