#include <iostream>
#include <stdio.h>

namespace N
{
	int a;
	double b;
}

int main()
{
	// 将命名空间中的成员a赋值为10
	N::a = 10;
	printf("%d\n", N::a);
	return 0;
}
