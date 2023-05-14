#include <iostream>

using namespace std;

class Test
{
private:
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
	cout << sizeof(Test) << endl;
	return 0;
}
