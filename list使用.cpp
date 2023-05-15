#include <list>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    auto pos = find(lt.begin(), lt.end(), 2);
    // 在2的位置插入9
    lt.insert(pos, 9);
    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v(2, 7);
    pos = find(lt.begin(), lt.end(), 1);
    // 在1位置插入2个7
    lt.insert(pos, v.begin(), v.end());
    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
