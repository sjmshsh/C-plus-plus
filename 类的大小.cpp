#include <iostream>
using namespace std;

// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};


int main()
{
	cout << sizeof(A1) << endl; // 4
	cout << sizeof(A2) << endl; // 1
	cout << sizeof(A3) << endl; // 1
	return 0;
}
