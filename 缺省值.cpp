#include <iostream>

using namespace std;

class A
{
public:
	void Print()
	{
		cout << _a << endl;
		cout << _p << endl;
	}
private:
	// 非静态成员变量，可以在成员声明时给缺省值
	int _a = 10;
	int* _p = (int*)malloc(4);
	static int _n; // 静态成员变量不能给缺省值
};

int main()
{

	return 0;
}
