#include<bits/stdc++.h>
using namespace std;

void maxOrder(vector<int> & v)
{
    if(v.size() == 0)
        return;
    
    sort(v.begin(), v.end(), [](int aa, int bb) {
        string a = to_string(aa), b = to_string(bb);
        for(int i = 0; i < min(a.size(), b.size()); ++ i) {
            if(a[i] > b[i]) {
                return true;
            } else if(a[i] < b[i]) {
                return false;
            } else if(a[i] == b[i]){
                continue;
            }
        }
        return true;
    });
    
    for(int & i : v) {
        cout << i;
    }
    cout << endl;
}



int main()
{
    vector<int> v{123,456,781, 789};
    // cout << maxOrder(v) << endl;
    maxOrder(v);
    return 0;
}