#include <bits/stdc++.h>
using namespace std;

class A
{
public:
      int n;
      virtual void Foo(void){}
};

int main()
{
     A a;
     char *p1 = reinterpret_cast<char*>(&a);
     char *p2 = reinterpret_cast<char*>(&a.n);
     if(p1 == p2)
     {
        cout<<"vPtr is in the end of class instance!"<<endl;
     }else
     {
        cout<<"vPtr is in the head of class instance!"<<endl;
     }
     return 1;
}