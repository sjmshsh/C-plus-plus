#include <iostream>
#include <stdio.h>

using namespace std;

// 形参列表必须不同（形参列表指参数个数，参数类型还有参数顺序）
int Add(int x, int y)
{
	return x + y;
}

double Add(double x, double y)
{
	return x + y;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;
	return 0;
}
