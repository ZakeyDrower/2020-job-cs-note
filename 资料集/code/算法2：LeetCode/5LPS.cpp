#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if(s.size() < 2)
        return s;
    
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    string res = "";
    for(int i = s.size()-1; i >= 0; i--){
        for(int j = i; j < s.size(); j++){
            dp[i][j] = i==j ? true : (
                j-i > 1 ? (
                    dp[i+1][j-1] && s[i] == s[j]
                ) : s[i] == s[j]
            );
            if(dp[i][j] && j-i+1 > res.size()){
                res = string(s.begin()+i, s.begin()+j+1);
            }
        }
    }

    return res;
}

int main()
{
    cout << longestPalindrome("bb") << endl;
    return 0;
}