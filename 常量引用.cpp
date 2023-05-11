#include <iostream>
#include <stdio.h>

using namespace std;


// 我们可以将被const修饰了的类型理解为安全的类型，因为其不能被修改。
// 我们若将一个安全的类型交给一个不安全的类型（可被修改），那么将不会成功。
int main()
{
	const int a = 10;
	// int& ra = a;  该语句编译时会报错，a为常量
	const int& ra = a; // 正确

	// int& b = 10; // 该语句编译时会出错，10为常量
	const int& b = 10; // 正确
	return 0;
}
