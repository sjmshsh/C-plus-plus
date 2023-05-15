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

// 对T1为interesting的类进行特化
template<class T2>
class Dragon<int, T2>
{
public:
	Dragon()
	{
		cout << "Dragon<int, T2>" << endl;
	}
private:
	int _D1;
	T2 _D2;
};

int main()
{
	Dragon<int, int> d1;
	Dragon<double, int> d2;
	return 0;
}
