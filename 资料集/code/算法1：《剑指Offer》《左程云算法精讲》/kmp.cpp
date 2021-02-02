#include<bits/stdc++.h>
using namespace std;

int search(const string & s, const string & p, const vector<int> & next)
{
    int i = 0, j = 0;
    while(i != s.size()) {
        while(s[i] == p[j]) {
            if(++j == p.size()) // 匹配成功
                return i - j + 1;
            if(++i == s.size()) // 匹配失败
                return -1;            
        }
        j = next[j];
    }
    return -1;
}

vector<int> genNext(string pat)
{
    vector<int> next(pat.size(), -1);
    if(next.size() < 2)
        return next;
    next[1] = 0;
    for(int i = 2; i < next.size(); ++ i) {
        int pre = next[i-1];
        while(pre != -1) {
            if(pat[i-1] == pat[pre]) {
                next[i] = pre + 1;
                break;
            } else {
                pre = next[pre];
            }
        }
        if(pre == -1)
            next[i] = 0;
    }
    return next;
}

int my_kmp(string & txt, string & pat) {
    if(pat.size() > txt.size())
        return -1;
    return search(txt, pat, genNext(pat));
}

int main()
{
    string pat = "abkabdabkabke";
    string txt = "abkababkaabkabdabkabkeabk";
    cout << my_kmp(txt, pat);
}