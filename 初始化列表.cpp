#include <iostream>

using namespace std;

// 类中包含一下变量必须放在初始化列表进行初始化
// 引用类型
// const成员变量
// 自定义类型成员(该类没有默认的构造函数)
// 成员变量在类中声明的次序就是其在初始化列表中初始化的顺序
// 与其在初始化列表中的先后顺序无关
class Date
{
public:
	// 构造函数
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{

	return 0;
}
