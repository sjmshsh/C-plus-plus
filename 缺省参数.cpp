#include <iostream>
#include <stdio.h>

using namespace std;

void Print(int a = 0)
{
	cout << a << endl;
}

int main()
{
	// 打印默认值0
	Print();
	// 指定了实参，使用指定的实参
	Print(10);
	return 0;
}
