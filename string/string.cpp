#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString1()
{
	String s1("hello bit!!!");
	String s2(s1);
}

int main()
{
	system("pause");
	return 0;
}