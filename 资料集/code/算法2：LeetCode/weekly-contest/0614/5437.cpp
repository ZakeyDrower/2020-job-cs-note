#include <bits/stdc++.h>
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    if(arr.size() == 0) return arr.size();
    if(k >= arr.size()) return 0;

    unordered_map<int,int> map;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i : arr)
        map[i] += 1;

    for(auto it : map)
        q.push(it.second);
    while(!q.empty()){
        if(k >= q.top()){
            k -= q.top();
            q.pop();
        }else{
            break;
        }
    }
    return q.size();
}