#include <iostream>

using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;

// 栈：存储非静态局部变量，函数参数，函数返回值等
// 堆：用于存储运行时动态内存分配
// 数据段：静态区，用于存储全局数据或者静态数据
// 代码段：常量区，可执行代码或者只读常量

void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1,2,3,4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
}

int main()
{
	Test();
	return 0;
}
