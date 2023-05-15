#include "iostream"
#include "string"

using namespace std;

struct Point {
    int _x;
    int _y;
};

int main() {
    // 使用大括号对内置类型进行初始化
    int x1 = {1}; // 可以添加等号
    int x2{2}; // 可以不添加等号

    // 使用大括号对数组元素进行初始化
    int array1[]{1, 2, 3, 4, 5};
    int array2[5]{0};

    // 使用大括号对结构体元素进行初始化
    Point p{1, 2}; // 可以不添加等号

    int *p1 = new int[4]{0};
    int *p2 = new int[4]{1, 2, 3, 4};
    return 0;
}
