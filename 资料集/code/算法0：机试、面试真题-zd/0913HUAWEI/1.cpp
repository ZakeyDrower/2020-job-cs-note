#include<bits/stdc++.h>
using namespace std;

string process(string str, char c)
{
    string res = "";
    for(char & x : str) {
        if(x < c) res += x;
    }
    return res;
}

int main()
{
    vector<string> list;
    char basechar;
    while(true) {
        string line;
        cin >> line;
        if(line.size() == 1) {
            basechar = line[0];
            break;
        }
        list.push_back(line);
    }
    cout << "size : " << list.size() << endl;
    for(string s : list) 
     cout << "    " << s << endl;

    string basestr, baseline;
    cin >> basestr;
    baseline = process(basestr, basechar);
    for(string & s : list) {
        string cur = process(s, basechar);
        if(baseline.find(cur) != string::npos)
            cout << s << endl;
    }
    return  0;
}

