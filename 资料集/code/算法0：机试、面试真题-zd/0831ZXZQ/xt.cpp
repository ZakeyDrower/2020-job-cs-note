#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int n1;
    int n2;
    A() : n2(0), n1(n2 + 2) {}
    void print()
    {
        cout << n1 << ' ' << n2;
    }
};

int main()
{
    A  a;
    a.print();
    return 0;
}