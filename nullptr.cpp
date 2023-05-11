#include <iostream>
using namespace std;
void Fun(int p)
{
	cout << "Fun(int)" << endl;
}
void Fun(int* p)
{
	cout << "Fun(int*)" << endl;
}
int main()
{
	Fun(0);           //打印结果为 Fun(int)
	Fun(NULL);        //打印结果为 Fun(int)
	Fun((int*)NULL);  //打印结果为 Fun(int*)
	return 0;
}
