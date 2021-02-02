#include<bits/stdc++.h>
using namespace std;

map<char, int> dit;

void initdit()
{
    int i = 10;
    for(char c = 'A'; c <= 'Z'; ++c) {
        dit[c] = i++;
    }
    i = 0;
    for(char c= '0'; c <= '9'; ++ c) {
        dit[c] = i++;
    }
}

int parse(string & str, int x)
{
    int base = 1;
    int res = 0;
    for(int i = str.length()-1; i >= 0; -- i) {
        res += base*dit[str[i]];
        base *= x;
    }
    return res;
}

int run(string & str, int l, int r)
{
    int sum = 0;
    for(int i = l; i <= r; ++ i) {
        sum += parse(str, i);
    }
    return sum % 2;
}
/*
2
101 2 3
4B 12 14
*/

int main()
{
    initdit();
    int T;
    cin >> T;
    while(T--) {
        string str;
        int l , r;
        cin >> str;
        cin >> l >> r;
        cout << run(str, l, r) << endl;
    }
    return 0;
}
