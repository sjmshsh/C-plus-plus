#include <iostream>
#include <functional>
#include <set>
#include <queue>
using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(2);
	s.insert(3);
	// 遍历容器的方式一
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	// 删除元素的方式1
	s.erase(3);
	// 删除元素的方式2
	// 查找值为1的元素
	set<int>::iterator pos = s.find(1);
	if (pos != s.end())
	{
		s.erase(pos);
	}
	// 遍历容器的方式二
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	// 容器中国值为2的元素个数
	cout << s.count(2) << endl;
	// 容器大小
	cout << s.size() << endl;
	// 清空容器
	s.clear();
	return 0;
}
