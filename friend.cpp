#include <iostream>

using namespace std;

class A
{
	// 声明B是A的友元类
	friend class B;
public:
	A(int n = 0)
		:_n(n)
	{}
private:
	int _n;
};

class B
{
public:
	void Test(A& a)
	{
		// B类可以直接访问A类中的私有成员变量
		cout << a._n << endl;
	}
};

int main()
{
	return 0;
}
