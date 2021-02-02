#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j;
    string s;
    cin >> i >> j;
    getline(cin, s);
    int bi=0, bj=0;
    for(char & c : s) {
        switch(c){
            case 'L':
                --bj;
                break;
            case 'R':
                ++bj;
                break;
            case 'U':
                --bi;
                break;
            case 'D':
                ++bi;
                break;
        }
    }
    cout << i+bi << ' ' << j+bj << endl;
    return 0;
}