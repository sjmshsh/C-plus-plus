#include <iostream>

using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}

	~A()
	{}
private:
	int _a;
};

int main()
{
	// new(place_address)type
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A;

	// new(place_address)type(initializer-list)形式
	A* p2 = (A*)malloc(sizeof(A));
	new(p1)A(2021);

	// 析构函数也可以显示调用
	p1->~A();
	p2->~A();
	return 0;
}
