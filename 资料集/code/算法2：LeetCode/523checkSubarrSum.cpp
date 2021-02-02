#include<bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() < 2) return false;
    for(int i = 0; i < nums.size()-1; i++)
        if(nums[i]==0 && nums[i+1]==0) return true;
    if(k == 0) return false;
    k = k<0 ? -k : k;
    unordered_map<int, int> map;
    map[0] = -1;
    for(int i = 0; i <  nums.size(); i++){
        nums[i] = (((i==0 ? 0 : nums[i-1]) + nums[i]) % k + k) % k;
        if(map.count(nums[i])){
            if(i-map[nums[i]]+1>2)
                return true;
        }else{
            map[nums[i]] = i;
        }
    }
    return false;
}

int main(){
    vector<int> vec({1,0});
    cout << checkSubarraySum(vec, 2);
    return 0;
}