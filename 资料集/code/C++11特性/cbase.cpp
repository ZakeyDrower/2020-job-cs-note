#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int * p = &a;
    shared_ptr<int> sp = make_shared<int>(a);
    shared_ptr<int> sp2 = make_shared<int>(a);
    shared_ptr<int> sp3(p);
    shared_ptr<int> sp4(p);
    //sp = &a;
    cout << &a << endl << p << '\n' << sp2 << "\n" << sp3 << "\n\n";

    cout << sp.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << ' ' << sp4.use_count() << endl;

    int b = 88;
    unique_ptr<int> up(&b);
    unique_ptr<int> up2(up);

    cout << *up << endl;

    size_t n = get_size();
    int * ip = new int[n];
    

}