#include"header.h"

class A {
private:
    static int a;
public :
    A() {};
};

int main()
{
    A a;
    A as[10];
    cout << sizeof(A) << endl << sizeof(as) << endl;
}