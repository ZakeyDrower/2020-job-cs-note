#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void func(T& param) {
    cout << "L val" << endl;
}
template<typename T>
void func(T&& param) {
    cout << "R val" << endl;
}

// not Perfect
// template<typename T>
// void warp(T&& param) {
//     func(param);
// }

// Perfect Foward
template<typename T>
void warp(T&& param) {
    func(std::forward<T>(param));
}

int main() {
    int num = 2019;
    warp(num);
    warp(2019);
    return 0;
}
// ————————————————
// 版权声明：本文为CSDN博主「卡尔曼和玻尔兹曼谁曼」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/theonegis/article/details/86568427