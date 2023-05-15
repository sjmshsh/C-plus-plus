#include "iostream"
#include "string"

using namespace std;

template<class T1, class T2>
void F(T1 t1, T2 t2) {
    // decltype可以将变量的类型声明为表达式指定的类型
    decltype(t1*t2) ret;
    cout << typeid(ret).name() << endl;
}

int main() {
    const int x = 1;
    double y = 2.2;

    decltype(x*y) ret;
    decltype(&x) p;
    cout << typeid(ret).name() << endl;
    cout << typeid(p).name() << endl;

    F(1, 'a');
    F(1, 2.2);
    return 0;
}
