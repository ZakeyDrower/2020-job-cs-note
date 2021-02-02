#include<bits/stdc++.h>
using namespace std;

int findMin(const vector<int> & nums, const int & target) 
{
    int l = 0, r = nums.size()-1, m;
    while(l <= r) {
        m = (l+r) / 2;
        if(nums[m] < target) l = m+1;
        else r = m-1; // ==
    }
    return (l>=nums.size() || nums[l]!=target) ? -1 : l;
}

int findMax(const vector<int> & nums, const int & target) 
{
    int l = 0, r = nums.size()-1, m;
    while(l <= r) {
        m = (l+r) / 2;
        if(nums[m] > target) r = m-1;
        else l = m+1; // ==
    }
    return nums[l-1]==target ? l-1 : -1;
}

int search(vector<int> nums, int target) {
    if(nums.size() == 0 || target < nums.front() || target > nums.back())
        return 0;
    int l = nums.front()==target ? 0 : findMin(nums, target);
    int r = nums.back()==target ? nums.size()-1 : findMax(nums, target);
    return (l==-1 && r==-1) ? 0 : r-l+1;
}


int lsearch(const vector<int> & nums, const int & target) {
    int l = 0, r = nums.size()-1, m;
    while(l <= r){
        m = (l+r)/2;
        if(nums[m] < target) l = m+1;
        else r = m-1;
    }
    return (l<nums.size() && nums[l]==target) ? l : -1;
}

int rsearch(const vector<int> & nums, const int & target) {
    int l = 0, r = nums.size()-1, m;
    while(l <= r){
        m = (l+r)/2;
        if(nums[m] <= target) l = m+1;
        else r = m-1;
    }
    return (nums[l-1]==target) ? l-1 : -1;
}

vector<int> searchRange(vector<int> nums, int target) {
    if(nums.size() == 0)
        return {-1,-1};
    return {lsearch(nums, target), rsearch(nums, target)};
}

int main()
{
    for(int i : searchRange({2,2}, 1)) cout << i << endl;
}