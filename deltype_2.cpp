#include "iostream"
#include "string"

using namespace std;

void* GetMemory(size_t size) {
    return malloc(size);
}

int main() {
    // 如果没有带参数  推导函数的类型
    cout << typeid(decltype(GetMemory)).name() << endl;
    // 如果带参数列表  推到的是函数返回值的类型  注意：此处只是推演，不会执行函数
    cout << typeid(decltype(GetMemory(0))).name() << endl;
    return 0;
}
