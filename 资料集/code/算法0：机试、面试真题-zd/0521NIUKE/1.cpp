#include <bits/stdc++.h>
using namespace std;

int doubleStr(string s)
{
    if(s == "")
        return 0;

    int n = s.size()/2;
    while(n>0){
        if(string(s.begin(),s.begin()+n) == string(s.begin()+n, s.begin()+n*2))
            return n*2;
        n--;
    }
    return 0;
}

int main()
{
    string s;
    while(cin >> s)
    cout << doubleStr(string(s.begin(), s.end()-1)) << endl;
    return 0;
}