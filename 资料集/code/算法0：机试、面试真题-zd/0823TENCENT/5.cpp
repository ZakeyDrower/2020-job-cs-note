#include <bits/stdc++.h>
using namespace std;

bool ok(string & s, int l, int r)
{
    while(l <= r) {
        if(s[l] != s[r]) {
            return false;
        }
        ++l;
        --r;
    }
    return true;
}

int run5(string & s)
{
    int len = s.size();
    vector<int> dp(len+1, 0);
    for(int i = 1; i <= len; ++ i) {
        dp[i] = 1010;
        for(int j = 1; j <= i; ++ j) {
            if(ok(s, j, i)) {
                if( j == 1)
                    dp[i] = 1;
                else
                    dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }
    return dp[len] - 1;
}   

int main()
{
    int T;
    string s;
    cin >> s;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        cout << run5(s) << endl;
    }
    return 0;
}