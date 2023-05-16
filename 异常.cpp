#include <iostream>
#include <string>

using namespace std;

void func1()
{
	throw string("这是一个异常");
}

void func2()
{
	func1();
}

void func3()
{
	func2();
}

int main()
{
	try
	{
		func3();
	}
	catch (const string& s)
	{
		cout << "错误描述: " << s << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}
