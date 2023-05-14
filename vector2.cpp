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
	// 获取值为2的元素迭代器
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	
	// 在2的位置插入10
	v.insert(pos, 10);

	pos = find(v.begin(), v.end(), 3);

	v.erase(pos);
	
	return 0;
}
