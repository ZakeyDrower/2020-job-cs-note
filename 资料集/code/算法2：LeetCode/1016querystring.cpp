#include <bits/stdc++.h>
using namespace std;

string tobin(int n)
{
    string s;
    while(n){
        s += n%2 + '0';
        n /= 2;        
    }
    reverse(s.begin(), s.end());
    return s;
}

bool queryString(string s, int n)
{
    for(int i = 0 ; i <= n; i ++){
        if(s.find(tobin(i)) == -1)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin >> n)
        cout << tobin(n) << endl;

    return 0;
}