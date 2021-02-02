#include "header.h"

// template<typename T>
// void func(T&& param) {
//     cout << param << endl;
// }

template<typename T>
void func(T& param) {
    cout << "Left val" << endl;
}
template<typename T>
void func(T&& param) {
    cout << "Right val" << endl;
}

int main() {
    int num = 2019;
    func(num);
    func(2019);
    return 0;
}