#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> ls;
    ls.push(-1);
    int res = 0;
    for(int i = 0; i < s.size(); ++ i) {
        if(s[i] == '(') {
            ls.push(i);
        }else{ // ls[i] == ')'
            ls.pop();
            if(ls.empty()) {
                ls.push(i);
            }else{
                res = max(res, i-ls.top());
            }
        }
    }
    return res;
}

int main() 
{
    string s = ")()())";
    cout << longestValidParentheses(s);
}