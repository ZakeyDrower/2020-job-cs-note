#include "header.h"

/**
// 旧式风格的类型转换
type(expr); // 函数形式的强制类型转换
(type)expr; // C语言风格的强制类型转换
// c++风格的类型转换
cast-name<type>(expression);
*/

class A { public : virtual void f() {cout << "A" << endl;}; };
class B :public A { public :virtual void f() {cout << "B" << endl;}; };
class C :public A { public :virtual void f() {cout << "C" << endl;}; };
class D :public B, public C { public : void f() {cout << "D" << endl;}; };

void static_cast_demo()
{
    int i = 0x12345;
    char c = 'c';
    int *pi = &i;
    char *pc = &c;

    c = static_cast<char>(i);
    //pc = static_cast<char *>(pi); // Error，static_cast不能用于基本类型指针间的转换
}

void const_cast_demo()
{
    const int &j = 1;
    int &k = const_cast<int &>(j);

    const int x = 2;
    int &y = const_cast<int &>(x);

    //int z = const_cast<int>(x);  // Error，const_cast的目标类型必须是指针或引用
}

void reinterpret_cast_demo()
{
    int i = 0;
    char c = 'c';
    int *pi = &i;
    char *pc = &c;

    pc = reinterpret_cast<char *>(pi);
    pi = reinterpret_cast<int *>(pc);
    pi = reinterpret_cast<int *>(i);
    //c = reinterpret_cast<char>(i); // Error，reinterpret_cast不能用于基本类型间的转换
}

void dynamic_cast_demo()
{
    int i = 0;
    int *pi = &i;
    //char *pc = dynamic_cast<char *>(pi); // Error，dynamic_cast只能用于有继承关系或交叉关系的类指针间的转换，且类中必须有虚函数
}

int main() 
{
    D* pD = new D();
    pD->f();
    C* pC = dynamic_cast<C*>(pD);
    pC->f();
    A* pA = dynamic_cast<A*>(pC);
    pA->f();

    static_cast_demo();
    const_cast_demo();
    reinterpret_cast_demo();
    dynamic_cast_demo();
}