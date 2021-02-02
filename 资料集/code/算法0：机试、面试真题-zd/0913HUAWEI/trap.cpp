#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    if(height.size() < 3) return 0;
    stack<pair<int,int>> s;
    s.push(make_pair(0,-1));
    int res = 0;
    int pretop = 0;
    for(int i = 0; i < height.size(); ++ i) {
        // 结算
        while(s.top().second != -1 && height[i] >= s.top().first) {
            pair<int, int> pt = s.top();
            s.pop();
            res += (min(height[i], pretop)-pt.first)*(pt.second-s.top().second);   
        }
        s.push(make_pair(height[i], i));
        if(height[i] >= pretop) {
            pretop = s.top().first;
        }
    }
    return res;
}

int main()
{
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v) << endl;
    return 0;
}