#include <bits/stdc++.h>
using namespace std;

int nlen(int num)
{
    return to_string(num).size();
}

void update(int & a, int & b, int & c, int & len)
{
    int sum = a+b+c;
    if(sum >= 10){
        int tc = c;
        c = sum%10;
        b = sum/10;
        a = tc;
        len = 2;
    }else{
        int tc=c, tb = b;
        c = sum;
        b = tc;
        a = tb;
        len = 1;
    }
}

int charatt(int a, int b, int c, int t)
{
    string s = to_string(a) + to_string(b) + to_string(c);
    if(s.size() >= t)
        return s[t-1]-'0';
    
    int len = s.size();
    int cur = len;
    while(cur < t){
        update(a, b, c, len);
        cur += len;
    }
    if(cur == t)
        return c;
    return b;
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        int a, b , c, t;
        cin >> a >> b >> c >> t;
        cout << charatt(a, b, c, t) << endl;
    }
    return 0;
}