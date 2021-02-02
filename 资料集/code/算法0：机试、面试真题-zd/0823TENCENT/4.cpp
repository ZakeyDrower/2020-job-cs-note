#include <bits/stdc++.h>
using namespace std;

int run(vector<int> & vec, int l, int r)
{
    int bottom = vec[l];
    for(int i = l+1; i <= r; ++i)
        bottom = min(bottom, vec[i]);
    
    int ans = bottom, pre = l;
    for(int i = l; i <= r; ++ i) {
        vec[i] -= bottom;
        if(vec[i] == 0) {
            ans += run(vec, pre, i-1);
            pre = i + 1;
        }
    }
    if(pre <= r) {
        ans += run(vec, pre, r);
    }

    return min(ans, r-l+1);
}

int main()
{
    int n;
    while(cin >> n) {
        vector<int> nums{0};
        int nn = n;
        while(nn--) {
            int i;
            cin >> i;
            nums.push_back(i);
        }
        cout << run(nums, 1, n) << endl;
    }
    return 0;
}