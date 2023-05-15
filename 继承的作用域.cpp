#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	void fun(int x)
	{
		cout << x << endl;
	}
};

class Student : public Person
{
public:
	void fun(double x)
	{
		cout << x << endl;
	}
};

int main()
{
	Student s;
	// 直接调用子类当中的成员函数fun
	s.fun(3.14);
	// 直接调用父类当中的成员函数fun
	s.Person::fun(20);
	return 0;
}
