#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;
	// 调用pair的构造函数，构造一个匿名对象插入
	m.insert(pair<int, string>(2, "two"));
	// m.insert(make_pair(2, "two"));
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	for (auto e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl;
	return 0;
}
