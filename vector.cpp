#include <iostream>
#include <string>
#include <vector>
#include "SkipList.h"

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 在容器开头插入0
	v.insert(v.begin(), 0);

	// 在容器开头插入5个-1
	v.insert(v.begin(), 5, -1);

	// 山粗容器中的第一个元素
	v.erase(v.begin());

	// 删除在该迭代器区间内的元素 [)
	v.erase(v.begin(), v.begin() + 5);
	return 0;
}
