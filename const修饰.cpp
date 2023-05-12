#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)// 构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 赋值运算符重载函数
	// 参数类型设置为引用，并用const进行修饰
	// 函数的返回值使用引用
	// 赋值前检查是否给自己赋值
	// 引用返回的是*this
	// 一个类如果没有显示定义赋值运算符重载，编译器也会自动生成一个
	// 完成对象按字节序的值拷贝
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	void Print()const  // 打印函数
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	return 0;
}
