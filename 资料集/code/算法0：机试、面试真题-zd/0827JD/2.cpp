#include<bits/stdc++.h>
using namespace std;

void search(vector<int>& arr, int i, int m, int & count)
{
    if(i == arr.size() || m < 0)
        return;
    if(m == 0){
        count ++;
        count %= 1000000007;
        return;
    }
    // use arr[i]
    search(arr, i+1, m-arr[i], count);
    // dont use arr[i]
    search(arr, i+1, m, count);
}

int runzd(vector<int> & arr, int & m) 
{
    int count = 0;
    int i = 0;
    search(arr, i, m, count);
    return count;
}

int main()
{
    int n, m, t;
    cin >> n >> m;
    vector<int> arr;
    while(n--) {
        cin >> t;
        arr.push_back(t);
    }
    cout << runzd(arr, m) << endl;
    return 0;
}

/*
3 3
1
2
2
*/