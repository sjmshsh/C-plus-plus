#include <iostream>
#include <list>
using namespace std;

bool single_digit(const int& val)
{
    return val < 10;
}

int main()
{
    list<int> lt;
    lt.push_back(10);
    lt.push_back(4);
    lt.push_back(7);
    lt.push_back(18);
    lt.push_back(2);
    lt.push_back(5);
    lt.push_back(9);
    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl; //10 4 7 18 2 5 9
    lt.remove_if(single_digit); //删除容器当中值小于10的元素
    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl; //10 18
    return 0;
}
