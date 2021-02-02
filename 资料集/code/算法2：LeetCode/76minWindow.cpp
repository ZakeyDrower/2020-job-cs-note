#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if(s=="" || t=="" || s.size()<t.size())
        return "";

    int minlen = numeric_limits<int>::max();
    string res = "";

    unordered_map<char, int> map;
    for(char c : t) map[c] ++;

    int match = 0;
    int i = 0, j = 0;
    while(j < s.size()){
        map[s[j]]--;
        if(map[s[j]] >= 0)
            match ++;
        if(match == t.size()){
            while(map[s[i]] < 0){
                map[s[i++]]++;
            }
            res = j-i+1 < minlen ? string(s.begin()+i, s.begin()+j+1) : res;
            minlen = res.size();
            match--;
            map[s[i++]]++;
        }
        j++;
    }
    return minlen==numeric_limits<int>::max() ? "" : res;
}

int main()
{
    cout << minWindow("cabwefgewcwaefgcf", "cae") << endl;
    return 0;
}


