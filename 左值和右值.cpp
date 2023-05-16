#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 以下的p，b，c，*p都是左值
	int* p = new int(0);
	int b = 1;
	const int c = 2;

	// 以下几个是对上面左值的左值引用
	int*& rp = p;
	int&rb = b;
	const int& rc = c;
	int& pvalue = *p;

	// 以下几个是常见的右值
	// 10
	// x + y
	// fmin(x, y)

	return 0;
}
