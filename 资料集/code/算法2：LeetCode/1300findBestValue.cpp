#include <bits/stdc++.h>
using namespace std;

int findBestValue(vector<int> & arr, int target) 
{
    if(arr.size() == 0) return 0;

    int res;
    int l = 0, r = numeric_limits<int>::min();
    for(int & a : arr) r = max(a, r);
    while(l < r) {
        int m = (l + r) / 2;
        
    }
}

