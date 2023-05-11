#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	auto b = &a;   //自动推导出b的类型为int*
	auto* c = &a;  //自动推导出c的类型为int*
	auto& d = a;   //自动推导出d的类型为int
	//打印变量b,c,d的类型
	cout << typeid(b).name() << endl;//打印结果为int*
	cout << typeid(c).name() << endl;//打印结果为int*
	cout << typeid(d).name() << endl;//打印结果为int
	return 0;
}
