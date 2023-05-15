#include <iostream>
#include <functional>
#include <set>
#include <queue>
using namespace std;

int main()
{
	multiset<int> ms;
	ms.insert(1);
	ms.insert(4);
	ms.insert(4);
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
