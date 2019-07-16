#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	//// 1.�޲ι��캯��
	//Date()
	//{}
	// 2.���ι��캯��
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
	//Date d1; // �����޲ι��캯��
	Date d2(2019, 1, 1); // ���ô��εĹ��캯��

	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	Date d3();
}

//C++�����ͷֳ���������(��������)���Զ������͡��������;����﷨�Ѿ�����õ����ͣ���int / char...��
//�Զ������;�������ʹ��class / struct / union�Լ���������ͣ���������ĳ��򣬾ͻᷢ��
//����������Ĭ�ϵĹ��캯������Զ����ͳ�Ա_t���õ�����Ĭ�ϳ�Ա����

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
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ֱ�ӳ�ʼ����
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
	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
	d1 = 2019;
}