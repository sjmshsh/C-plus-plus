#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// N: 非类型模板参数
template<class T, size_t N>
class StaticArray
{
public:
	size_t arraysize()
	{
		return N;
	}
private:
	// 利用非类型模板参数指定静态数组的大小
	T _array[N];
};

int main()
{
	// 定义一个大小为10的静态数组
 	StaticArray<int, 10> a1;
	cout << a1.arraysize() << endl; // 10
	// 定义一个大小为100的静态数组
	StaticArray<int, 100> a2; 
	cout << a2.arraysize() << endl;
	return 0;
}
