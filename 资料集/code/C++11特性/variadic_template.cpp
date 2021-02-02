#include <bits/stdc++.h>
using namespace std;

void print() {};

template<typename T, typename... Types>
void print(const T& fir, const Types&... args)
{
    cout << "fir and args" << endl;
    cout << fir << endl;
    print(args...);
}

template<typename... Types>
void print(const Types&... args)
{
    cout << "args" << endl;
    print(args...);
}

int main()
{
    print(23, "hello world", 13.45, 'd');
}