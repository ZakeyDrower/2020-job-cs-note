#include<bits/stdc++.h>
using namespace std;

uint32_t reverse(uint32_t & num)
{
    uint32_t a = 0;
    while(num > 0) {
        a *= 10;
        a += num%10;
        num /= 10;
    }
    return a;
}

string to5jz(uint32_t num)
{
    string res = "";
    while(num) {
        res += '0'+num%5;
        num/=5;
    }
    reverse(res.begin(), res.end());
    return res;
}

string process(uint32_t & num)
{
    uint32_t n = reverse(num);
    //cout << n << endl;
    return to5jz(n);
}

int main()
{
    uint32_t num;
    while(cin >> num)
    {
        cout << process(num) << endl;
    }
    return 0;
}