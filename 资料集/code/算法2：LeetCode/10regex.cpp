#include <bits/stdc++.h>
using namespace std;

bool search(const string & s, const string & p, int i, int j)
{
    if(i == s.size() && j == p.size())
        return true;
    if(j == p.size()) return false;

    if(i == s.size()) {
        if(j < p.size()-1 && p[j+1] == '*')
            return search(s, p, i, j+2);
        return false;
    } else {
        if((j < p.size()-1 && p[j+1] != '*') || j==p.size()-1) {
            return (s[i] == p[j] || p[j] == '.') && search(s, p, i+1, j+1);
        } // pat.next == *
        else {
            return ((s[i] == p[j] || p[j] == '.') && search(s, p, i+1, j))
                || search(s, p, i, j+2);
        }
    }
}

bool isMatch(string s, string p)
{
    return search(s, p, 0, 0);
}

int main()
{
    string s, p;
    while(cin >> s >> p)
    {
        cout << isMatch(s, p) << endl;
    }
    return 0;
}