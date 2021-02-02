#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> s;
    cin >> n;
    vector<vector<char>> trans(n,vector<char>(2,0));
    unordered_map<char, char> map;
    unordered_map<char, 
    for(int i = 0;i < n;i++)
    {
        cin >> trans[i][0] >> trans[i][1];
        map[trans[i][0]] = trans[i][1];
    }
    for(int i = 0;i < s.size();i++)
    {
        while(map.find(s[i]) != map.end())
        {
            s[i] = map[s[i]];
        }
    }
    cout << s << endl;
}