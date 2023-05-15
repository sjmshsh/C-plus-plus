#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<class T1, class T2>
class Dragon
{
public:
	Dragon()
	{
		cout << "Dragon<T1, T2>" << endl;
	}
private:
	T1 _D1;
	T2 _D2;
};

// 两个参数偏特化为指针类型
template<class T1, class T2>
class Dragon<T1*, T2*>
{
public:
	Dragon()
	{
		cout << "Dragon<T1*, T2*>" << endl;
	}
private:
	T1 _D1;
	T2 _D2;
};

// 两个参数偏特化为引用类型
template<class T1, class T2>
class Dragon<T1&, T2&>
{
public:
	Dragon()
	{
		cout << "Dragon<T1&, T2&>" << endl;
	}
private:
	T1 _D1;
	T2 _D2;
};

int main()
{
	Dragon<int, int> d1;
	Dragon<double, int> d2;
	Dragon<int*, int*> d3;
	Dragon<int&, int&> d4;
	return 0;
}
