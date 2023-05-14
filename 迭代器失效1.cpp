#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// 在STL里，我们不能以指针来看待迭代器，指针和内存是绑定的，而迭代器和元素是绑定的
// 删除了之后，该迭代器就失效了，在对其重新赋值之前，不能再访问该迭代器
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// 获取值为2的元素的迭代器
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	v.insert(pos, 10);

	v.erase(pos);
	return 0;
}
