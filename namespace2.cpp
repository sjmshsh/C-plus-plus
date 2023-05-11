#include <iostream>
#include <stdio.h>

namespace N
{
	int a;
	double b;
}

// 将命名空间中的成员a引入
using N::a;

int main()
{
	a = 10;
	printf("%d\n", a);
	return 0;
}
