/**
 * C++ RVO
 * https://www.jianshu.com/p/dcd3390c5c84
 */

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base() { cout << "default ctor" << endl; };
    Base(const Base &b) { cout << "copy ctor " << endl; }
    Base &operator=(const Base &b)
    {
        cout << "operator=" << endl;
        a = b.a;
        return *this;
    }
    Base &operator=(Base &&b)
    {
        cout << "move operator=" << endl;
        a = b.a;
        return *this;
    }
    Base(Base &&b) { cout << "move ctor" << endl; }
    ~Base() { cout << "dtor " << endl; };
    int a = 0;
    int b = 0;
    double c = 1.1;
    struct Base *nb = nullptr;
};

class Child1 : public Base {};
class Child2 : public Base {};

Base func()
{
    Base a;
    return a;
}

Base func(int i)
{
    if (i > 0)
    {
        Base a;
        return a;
    }
    else
    {
        Base b;
        return b;
    }
}

Base &&movefunc()
{
    Base a;
    return std::move(a);
}

Base getChild(int i)
{
    if(i > 0) {
        Child1 a;
        return a;
    } else {
        Child2 b;
        return b;
    }
}

int main()
{
    cout << endl;
    const Base &a = func();  // g++: default                clang++: default
    cout << endl;
    const Base &b = func(0); // g++: default, move          clang++: default 
    cout << endl;
    Base c = func(0);        // g++: default, move          clang++: default
    cout << endl;
    Base d = func(0);        // g++: default, move          clang++: default
    cout << endl;
    d = func(0);             // g++: default, move, move=   clang++: default, move=

    cout << endl
         << "RVO :" << endl
         << endl;

    func();             // g++: default          clang++: default
    cout << endl;
    Base e = func();    // g++: default          clang++: default
    cout << endl;
    e = func();         // g++: default, move=   clang++: default, move=
    cout << endl;

    cout << "std::move() :" << endl
         << endl;

    movefunc();             // g++: default         clang++: default
    cout << endl;
    Base f1 = movefunc();   // g++: default, move   clang++: default, move
    cout << endl;
    Base &&f = movefunc();  // g++: default         clang++: default
    cout << endl;
    f = movefunc();         // g++: default, move=  clang++: default, move=

    cout << endl;

    cout << "rRef :" << endl;

    Base && aa = func(0);   // g++: default, move  clang++: default

    cout << endl;

    cout << "Inherit : " << endl;

    Base && child = getChild(2);


}