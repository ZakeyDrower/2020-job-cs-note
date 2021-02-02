#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int  k) {
    if(s == "") return 0;

    int l=0, r=0, res = 1, mostChar = 0;
    unordered_map<char, int> map;
    while(r<s.size()) {
        map[s[r]] ++;
        mostChar = max(mostChar, map[s[r]]);
        if((r-l+1) > mostChar+k) {
            map[s[l++]] --;
            res = max(res, r-l+1);
        }
        res = max(res, r-l+1);
        r++;
    }
    return res;
}