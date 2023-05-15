#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	// 构造函数
	Person(const string& name = "zuoyuqi")
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	// 拷贝构造函数
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	// 赋值运算符重载
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
private:
	string _name;
};

class Student :public Person
{
public:
	~Student()
	{
		cout << "~Student()" << endl;
	}

	Student(const string& name, int id)
		:Person(name) // 调用基类的构造函数初始化基类的那一部分成员
		, _id(id)  // 初始化派生类成员
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s)
		, _id(s._id)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			// 调用基类的operator=完成基类成员的赋值
			Person::operator=(s);
			_id = s._id;
		}
		return *this;
	}
private:
	int _id;
};

int main()
{

	return 0;
}
