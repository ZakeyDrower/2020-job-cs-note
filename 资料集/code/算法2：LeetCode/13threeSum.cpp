#include "header.h"

void sh(vector<int> & nums, vector<vector<int>> & res, int ci, int i, int j, int t){
    while(i < j) {
        if(nums[i]+nums[j] < t){
            i++;
        }else if(nums[i]+nums[j] > t) {
            j--;
        }else {
            if(i==ci+1 || nums[i]!=nums[i-1])
                res.push_back(vector<int>{nums[ci], nums[i], nums[j]});
            i++;
            j--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> & nums)
{
    vector<vector<int>> res;
    if(nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; ++i) {
        if(i == 0 || nums[i] != nums[i-1])
            sh(nums, res, i, i+1, nums.size()-1, 0-nums[i]);
    }
    return res;
}

int main()
{
    vector<int> a{-1, 0, 1, 2, -1, -4};
    auto res = threeSum(a);
    for(auto & v : res)
    for(auto & b : v)
    cout << b << ' ';
}