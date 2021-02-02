#include<bits/stdc++.h>
using namespace std;

long long parse(string & s)
{
    long long base = 1;
    long long res = 0;
    for(int i = s.size()-1; i >= 0; --i) {
        res += base * (s[i]-'a'+1);
        base *= 26;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        if(a.size() != n || b.size() != n){
            cout << 0 << endl;
            continue;
        }
        
        long long numa = parse(a);
        long long numb = parse(b);
        if(numa >= numb)
            cout << 0 << endl;
        else
            cout << numb-numa-1 << endl;
    }
    return 0;
}

/*
4
1 z a
1 a z
2 az bb
3 bbb bbb

*/