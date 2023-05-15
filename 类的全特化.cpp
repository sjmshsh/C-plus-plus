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

// 对于T1是double  T2是int时进行特化
template<>
class Dragon<double, int>
{
public:
	Dragon()
	{
		cout << "Dragon<double, int>" << endl;
	}
private:
	double _D1;
	int _D2;
};

int main()
{
	Dragon<int, int> d1;
	Dragon<double, int> d2;
	return 0;
}
