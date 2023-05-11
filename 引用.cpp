#include <iostream>
#include <stdio.h>

using namespace std;



int main()
{
	int a = 10;
	int& b = a; // 给a变量取了一个别名
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}
