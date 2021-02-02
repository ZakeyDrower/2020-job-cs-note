#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> & wordDict)
{
    if(s == "") return true;
    if(wordDict.size() == 0) return false;

    unordered_set<string> set;
    for(auto & w : wordDict) set.insert(w);
    // dp(i) = dp(j) && set.count(string(j+1, i))
    vector<bool> dp(s.size(), false);
    dp[0] = set.count(string(s.begin(), s.begin()+1));
    for(int i = 0; i < s.size(); ++ i) {
        dp[i] = set.count(string(s.begin(), s.begin()+i+1));
        if(dp[i]) continue;
        for(int j = 0; j < i; ++ j) {
            dp[i] = dp[j] && set.count(string(s.begin()+j+1, s.begin()+i+1));
            if(dp[i]) break;
        }
    }

    return dp.back();
}

int main() {
    vector<string> v{"ab","cd"};
    string s = "abcd";
    cout << wordBreak(s, v);
}