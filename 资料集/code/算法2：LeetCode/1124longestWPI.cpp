#include <bits/stdc++.h>
using namespace std;

int longestWPI(vector<int> & h) {
    for(int & i : h) i = i>8 ? 1 : -1;
    vector<int> ps(h.size()+1, 0);
    for(int i = 1; i < ps.size(); ++ i)
        ps[i] = ps[i-1] + h[i-1];
    stack<int> s;
    s.push(0);
    for(int i = 1; i < ps.size(); ++ i)
        if(ps[i]<ps[s.top()])
            s.push(i);
    int res = 0;
    for(int i = ps.size()-1; i > 0; -- i){
        if(s.top() == i)
            s.pop();
        while(!s.empty() && ps[i]>ps.at(s.top())) {
            res = max(res, i-s.top());
            s.pop();
        }
        if(s.empty()) break;
    }
    return res;
}

int main()
{
    vector<vector<int>>hs{
        {9,9,6,0,6,6,9},
        {6,6,9},
        {6,9,9}
        };
    for(auto & h : hs)
        cout << longestWPI(h) << endl;
}