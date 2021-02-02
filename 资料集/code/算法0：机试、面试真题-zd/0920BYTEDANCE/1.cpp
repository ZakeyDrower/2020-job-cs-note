#include<bits/stdc++.h>
using namespace std;

vector<int> genNext(string & str) {
    vector<int> next(str.size() + 1, -1);
    if(str.size() < 2)
        return next;
    // next[1] = 0;
    for(int i = 1; i <= str.size(); ++ i) {
        int pre = next[i-1];
        while(pre != -1) {
            if(str[i-1] == str[pre]) {
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

int main()
{
    string str;
    cin >> str;
    // str += " ";
    if(str.size() < 2){
        cout << str << endl;
    }else{
        vector<int> next = genNext(str);
        int len = str.size();
        if(str.size() % (len - next[len]) == 0)
            cout << string(str.begin(), str.begin()+(len - next[len])) << endl;
        else
            cout << str << endl;
    }
    return 0;
}