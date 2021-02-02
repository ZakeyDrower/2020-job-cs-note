#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    // nums == {}
    if(nums.size() == 0) return 1;
    // nums not contains(1)
    bool cont1 = false;
    for(int i : nums) if(i==1) cont1 = true;
    if(!cont1) return 1;
    // nums.contains(1) == true
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] <= 0 || nums[i] > nums.size()) nums[i] = 1;
    for(int i = 0; i < nums.size(); i++){
        nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1]);
    }
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] > 0)
            return i+1;
    return nums.size()+1;
}

int main()
{
    vector<int> vec{3,4,-1,1};
    cout << firstMissingPositive(vec);
}