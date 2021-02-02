#include<bits/stdc++.h>
#include"SmartPtr.h"
using namespace std;

int main()
{
    int num = 100;
    SmartPtr<int> a((int *) &num);
    SmartPtr<int> b(a);
    if(true){
        SmartPtr<int> c(b);
        cout << "process dtor() ..." <<endl;
    }
    b.~SmartPtr();
    cout << *(b.ptr) << " : " << *(b.use_count) << endl;
}