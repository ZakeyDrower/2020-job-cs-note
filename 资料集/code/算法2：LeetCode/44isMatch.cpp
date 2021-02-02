#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    if(s=="" && p=="") return true;
    if(s==""){
        if(p.find_first_not_of("*")==string::npos) return true;
        return false;
    }
    if(p=="") return false;
    
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0] = true;
    for(int i = 0; i < p.size(); ++ i) if(p[i]=='*' && dp[0][i]) dp[0][i+1]=true; else break;

    for(int i = 1; i <= s.size(); ++ i) {
        for(int j = 1; j <= p.size(); ++ j){
            if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }

    return dp.back().back();
}

int main()
{
    string s = "a";
    string p = "a*";
    cout << isMatch(s, p) << endl;
}