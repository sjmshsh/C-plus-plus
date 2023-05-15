#include "iostream"

using namespace std;

template<class T1, class T2>
auto Add(T1 t1, T2 t2)-> decltype(t1+t2)
{
    decltype(t1+t2) ret;
    cout << typeid(ret).name() << endl;
    return ret;
}

int main()
{
    cout << Add(1, 2) << endl;
    cout << Add(1, 2.2) << endl;
    return 0;
}
