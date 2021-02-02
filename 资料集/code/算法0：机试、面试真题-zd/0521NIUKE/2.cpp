// 给定字符串，最少能拼出来多少回文串
#include<bits/stdc++.h>
using namespace std;

int count(const string & s)
{
    unordered_map<char, int> map;
    int conut = 0;
    for(char c : s){
        map[c] ++;
    }
    for(auto p : map){
        conut += p.second%2;
    }
    return conut;
}


int main()
{
    string s;
    cin >> s;
    cout << count(s) << endl;
    return 0;
}