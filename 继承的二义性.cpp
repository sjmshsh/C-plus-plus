#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string _name; //姓名
};

class Student : public Person
{
protected:
	int _num; //学号
};

class Teacher : public Person
{
protected:
	int _id; //职工编号
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; //主修课程
};

int main()
{
	Assistant a;
	// a._name = "peter"; //二义性：无法明确知道要访问哪一个_name
	a.Student::_name = "hehe";
	a.Teacher::_name = "左笑笑";
	return 0;
}
