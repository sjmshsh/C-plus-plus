#include <iostream>
#include <stdio.h>

using namespace std;

// 当然引用也能做返回值，但是要特别注意，我们返回的数据不能是函数内部创建的普通局部变量，
// 因为在函数内部定义的普通的局部变量会随着函数调用的结束而被销毁。
// 我们返回的数据必须是被static修饰或者是动态开辟的或者是全局变量等不会随着函数调用的结束而被销毁的数据。


int& Add(int a, int b)
{
	static int c = a + b;
	return c;
}

int main()
{
	return 0;
}
