/**
 * hello world baidu
 * 
 * baidu world hello
 * 
 * 要求O1 空间复杂度
 */
#include<bits/stdc++.h>
using namespace std;

string parsestring(string & str)
{
    if(str.size() == 0)
        return str;
    // if(str.find(' ') == str.end())
    //     return str;
    
    reverse(str.begin(), str.end());
    int i = 0;
    while(i < str.size()) {
        int j = i + 1;
        while(j < str.size() && str[j] != ' ') {
            ++ j;
        }
        reverse(str.begin() + i, str.begin() + j);
        i = j + 1;

        if(str[i] == ' ') {
            while(i < str.size() && str[i] == ' ') {
                ++ i;
            }
        }
    }
    // move space
    int m = 0, n = 0;
    while(n < str.size()) {
        while(n < str.size() && str[n] == ' ') {
            ++ n;
        }
        while(n < str.size() && str[n] != ' ') {
            str[m++] = str[n++];
        }
        str[m++] = ' ';
    }
    while(m < str.size()) {
        str[m++] = ' ';
    }
    return str;
}

int main()
{
    vector<string> tests = {
        "hello world baidu",
        "Hello",
        "hello, world",
        "hello   world"
    };
    for(string & s : tests) {
        cout << parsestring(s) << endl;
    }

    return 0;
}