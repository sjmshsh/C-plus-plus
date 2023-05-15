#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> lt(3, 'a');
    // 新内容分配给容器 替换其当前内容
    lt.assign(3, 'b');
    for (auto e : lt) {
        cout << e << " ";
    }
    cout << endl;
    string s ("hello world");
    // 将新内容分配给容器，替换其当前内容
    lt.assign(s.begin(), s.end());
    for (auto e : lt) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
