#include <bits/stdc++.h>
using namespace std;

int getUpMedian(vector<int> & a, vector<int> & b, int l1, int r1, int l2, int r2) {
    while(l1 < r1) {
        int m1 = l1 + (r1-l1)/2;
        int m2 = l2 + (r2-l2)/2;
        if(a[m1] == b[m2]){
            return a[m1];
        } else if(a[m1] < b[m2]) {
            if((r1-l1+1)%2 == 0) r2 = m2, l1 = m1+1;
            else r2 = m2, l1 = m1; 
        } else if(a[m1] > b[m2]) {
            if((r1-l1+1)%2 == 0) r1 = m1, l2 = m2+1;
            else r1 = m1, l2 = m2;
        }
    }
    return min(a[l1], b[l2]);
}

double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
    vector<int> & sa = nums1.size() > nums2.size() ? nums2 : nums1;
    vector<int> & la = nums1.size() > nums2.size() ? nums1 : nums2;
    int m = sa.size(), n = la.size();

    if(n == 0) return 0;
    if(m == 0) {
        double res = (n%2==1) ? static_cast<double>(la[n/2]) : (static_cast<double>(la[n/2-1])+static_cast<double>(la[n/2]))/static_cast<double>(2.0);
        return res;
    }

    int k = (m + n) / 2 + 1; // k不可能小玉m，也不可能大于n
    bool even = (m+n)%2==0 ? 1 : 0;
    
    if(m < n){
        double up = la[k-m-1]>=sa[m-1] ?  la[k-m-1] : getUpMedian(sa, la, 0, m-1, k-m, k-1);
        if(!even) return up;

        k = (m + n) / 2;
        double down;
        if(k>m) {
            down = (la[k-m-1]>=sa[m-1]) ? la[k-m-1] : getUpMedian(sa, la, 0, m-1, k-m, k-1);
        } else {
            down = getUpMedian(sa, la, 0, m-1, k-m, k-1);
        }

        double res = (up + down)/2;
        return res;
    } else {
        double up, down;
        if(sa[k-n-1] >= la[n-1]) up = sa[k-n-1];
        else if(la[k-m-1] >= sa[m-1]) up = la[k-m-1];
        else up = getUpMedian(sa, la, k-n, m-1, k-m, n-1);

        k = m;
        down = getUpMedian(sa, la, 0, k-1, 0, k-1);
        double res = (up + down)/2;
        return res;
    }    
}



int main()
{
    vector<int>a{1,2}, b{3,4};
    double && res = findMedianSortedArrays(a, b);
    cout << setprecision(10) << res;
}