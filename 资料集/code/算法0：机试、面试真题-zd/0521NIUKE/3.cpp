// 合法的猜数字的个数
#include <bits/stdc++.h>
using namespace std;

long long g_res = 0;

bool isValid(vector<int> & v)
{
    // int len = v.size();
    // if(len == 1) return true;
    // for(int i = 1; i < len; i++){
    //     int j = 2;
    //     int k = (i+1)*j-1;
    //     while(j < sqrt(i) && (i+1)%j==0 && (i+1)/j-1 > 0){
    //         if(v[j] != v[i]  ||  v[(i+1)%j-1] != v[i])
    //             return false;
    //         j++;
    //     }
    // }

    int res = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] == 1){
            res *= i+1;
        }
    }
    for(int i = 1; i < v.size(); i++){
        if(v[i] == 0)
            if(res % (i+1) == 0)
                return false;
    }

    return true;
}

void dfs(vector<int> v, int cur, int n)
{
    if(cur == n){
        if(isValid(v)) 
        //{for(int i : v) cout << i ; cout <<endl; 
        g_res ++;
        g_res %= 100000007;
        //}
        return;
    }
    if(!isValid(v)) return;

    v.push_back(0);
    dfs(v, cur+1, n);
    v.back() = 1;
    dfs(v, cur+1, n);
}

int main()
{
    int n;

    //cout << isValid(vector<int>{1,0,0,0,1}) <<endl;
    while(cin >> n){
        g_res = 0;
        if(n < 3)
            cout << n << endl;
        else{
            vector<int> v;
            v.push_back(1);
            dfs(v, 1, n);
            cout << g_res << endl;
        }
    }
    
    return 0;
}