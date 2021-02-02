#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> & v, vector<int> & tmp, const int l, const int r, int & cnt)
{
    if(l >= r)
        return ;
    const int mid = l + ((r-l) >> 1);
    sort(v, tmp, l, mid, cnt);
    sort(v, tmp, mid+1, r, cnt);
    // merge
    int s1 = l, s2 = mid+1, e1 = mid, e2 = r;
    int t = l;
    while(s1<=e1 && s2<=e2) {
        if(v[s2] < v[s1]) {
            tmp[t++] = v[s2++];
            cnt += mid+1 - s1;
        } else {
            tmp[t++] = v[s1++];
        }
        // tmp[t++] = v[s1] < v[s2] ? v[s1++] : v[s2++];
        // process cnt
    }
    while(s1 <= mid) {
        tmp[t++] = v[s1++];
        cnt += e2 - s2 + 1;
    }
    while(s2 <= r) {
        tmp[t++] = v[s2++];
    }
    for(int t = l; t <= r; ++t ) {
        v[t] = tmp[t];
    }
}


int reversePairs(vector<int> & vec)
{
    int cnt = 0;
    vector<int> tmp(vec.size());
    sort(vec, tmp, 0, vec.size()-1, cnt);
    for(int & i : vec) cout << i << ' ' ; cout << endl;
    return cnt;
}


int main()
{
    vector<int> vec{0,6,2};
    cout << reversePairs(vec) << endl;
    return 0;
}