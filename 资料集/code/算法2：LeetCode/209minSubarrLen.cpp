#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0) return 0;

    int l = 0, r = 0, cur = nums[0],  res = INT_MAX;
    while(r < nums.size()) {
        if(cur < s){
            if(++r >= nums.size())
                break;
            cur += nums[r];
        }else{
            res = min(res, r-l+1);
            cur -= nums[l++];
        }
        cout << l << ' ' << r << " : " << cur <<  endl;
    }
    return res==INT_MAX ? 0 : res;
}

int minSubArrayLen2(int s, vector<int>& nums) {
    int i, j, sum;
    int res = INT_MAX;
    for(i=0, j=0;  j < nums.size(); ++j) {
        sum += nums[j];
        while(sum >= s) {
            res = std::min(res, j-i+1);
            sum -= nums[i++];
        }
    }
    return res==INT_MAX ? 0 : res;
}

int main()
{
    int s = 7;
    vector<int>v{2,3,1,2,4,3};
    cout << minSubArrayLen(s, v);
}