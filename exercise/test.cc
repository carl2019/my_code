#include <iostream>
#include <string>
using namespace std;

//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton()
	{};
	Singleton(Singleton const&);
	Singleton& operator = (Singleton const&);

	Singleton(Singleton const&) = delete;
	Singleton& operator = (Singleton const&) = delete;

	static Singleton m_instance;
};

Singleton Singleton::m_instance; //在程序的入口初始化

//懒汉模式
#include <mutex>
#include <thread>

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	static CGarbo Garbo;

private:
	Singleton(){};

	Singleton(Singleton const&);
	Singleton& operator = (Singleton const&);

	static Singleton* m_pInstance;
	static mutex m_mtx;
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}





























