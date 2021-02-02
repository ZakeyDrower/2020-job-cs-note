#include<iostream>
#include<thread>
using namespace std;

void foo()
{
    cout << "foo" << endl;
}

void bar(int x)
{
    cout << "bar " << x << endl;
}


int main()
{
    std::thread fir(foo);
    std::thread sec(bar, 0);

    cout << "main" << endl;

    fir.join();
    sec.join();

    cout << "end main" << endl;

    return 0;
}