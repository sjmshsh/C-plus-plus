#include "iostream"
#include "string"

using namespace std;

// 基类
class Person {
protected:
    string _name;
    string _sex;
    int _age;
};

class Student: public Person {
protected:
    int _stdid;
};

int main() {
    Student s;
    // 派生类对象赋值给基类对象
    Person p = s;
    // 派生类对象赋值给基类指针
    Person* ptr = &s;
    // 派生类对象赋值给基类引用
    Person& ref = s;
    return 0;
}
