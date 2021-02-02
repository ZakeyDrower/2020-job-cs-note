#include<iostream>
using namespace std;
//#pragma pack(1)

struct User {
    int16_t mid;
    char gendr;
    int16_t coin[4];
};

int main() {
    User u;
    cout <<sizeof(u);
    return 0;
}