#include<bits/stdc++.h>
using namespace std;

bool finish(vector<int> & arr)
{
    int a = arr[0];
    for(int i : arr) {
        if(a != i)
            return false;
    }
    return true;
}

int findmax(vector<int> & arr) {
    int res = 0;
    int m = arr[0];
    for(int i = 1; i < arr.size(); ++ i) {
        if(arr[i] > m) {
            m = arr[i];
            res = i;
        }
    }
    return res;
}

int minMagic(vector<int> arr)
{
    if(arr.size() < 2)
        return 0;
    int cnt = 0;
    while(! finish(arr)) {
        cnt += 1;
        // magic
        int keep = findmax(arr);
        for(int i = 0; i < arr.size(); ++i) {
            if(i != keep)
                arr[i] ++;
        }
    }
    return cnt;
}

vector<int> parsearr(vector<int> ori, int & cnt)
{
    vector<int> cur{1};
    int ele = cur[0];
    for(int i = 1; i < ori.size(); ++ i) {
        if(ori[i] == ori[i-1]) {
            cur.push_back(ele);
        } else if(ori[i] > ori[i-1]) {
            cnt += ori[i]-ori[i-1]-1;
            cur.push_back(++ele);
        }
    }
    return cur;
}

int method2(vector<int> & oarr) {
    sort(oarr.begin(), oarr.end());
    int res = 0;
    vector<int> arr = parsearr(oarr, res);
    int bottom = arr.front(), top = arr.back();
    res += top-bottom;
    int i = 1;
    while(i < arr.size() && arr[i] == bottom) {
        ++ i;
    }
    while(i < arr.size()) {
        if(arr[i] == arr[i-1])
            res += 1;
        else
            res += top - arr[i];
        ++i;
    }
    return res;
}

int main()
{
    int n, t;
    while(cin >> n) { 
        vector<int> a;
        while(n--) {
            cin >> t;
            a.push_back(t);
        }
        if (a.size() < 2)
            cout << 0 << endl;
        else{
            cout << "true: " << minMagic(a) << endl;
            cout << method2(a) << endl;
        }
    }
    
    return 0;
}