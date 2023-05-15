#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<int> lt1(4, 2);
    list<int> lt2(4, 6);
    // 将容器lt2拼接到容器lt1的开头
    lt1.splice(lt1.begin(), lt2);
    for (auto e : lt1) {
        cout << e << " ";
    }
    cout << endl; //6 6 6 6 2 2 2 2

    list<int> lt3(4, 2);
    list<int> lt4(4, 6);
    // 将容器lt4的第一个数据拼接到容器lt3的开头
    lt3.splice(lt3.begin(), lt4, lt4.begin());
    for (auto e : lt3)
    {
        cout << e << " ";
    }
    cout << endl; //6 2 2 2 2

    list<int> lt5(4, 2);
    list<int> lt6(4, 6);
    // 将容器lt6的指定迭代器区间内的数据拼接到容器lt5的开头
    lt5.splice(lt5.begin(), lt6, lt6.begin(), lt6.end());
    for (auto e : lt5)
    {
        cout << e << " ";
    }
    cout << endl; //6 6 6 6 2 2 2 2
    return 0;
}
