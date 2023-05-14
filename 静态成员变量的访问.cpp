#include <iostream>

using namespace std;

class Test
{
public:
	static int _n;
public:
	static void Fun()
	{
		cout << _n << endl;
		// cout << _a << endl; error 静态成员函数没有this指针，不能访问任何非静态成员
	}
};

// 静态成员变量的定义初始化
int Test::_n = 0;

int main()
{
	Test test;
	// 1. 通过类对象突破类域进行访问
	cout << test._n << endl;
	// 2. 通过类名突破类域进行访问
	cout << Test::_n << endl;
	// 3. 通过匿名对象突破类域进行访问
	cout << Test()._n << endl;
	return 0;
}
