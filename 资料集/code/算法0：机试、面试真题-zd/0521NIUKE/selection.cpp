#include<bits/stdc++.h>
using namespace std;

struct A{
    int a;
    short b;
    int c;
    char d;
};

struct B{
    int a;
    short b;
    char c;
    int d;
};

int main()
{
    cout << sizeof(A) << ' ' << sizeof(B);
    return 0;
}