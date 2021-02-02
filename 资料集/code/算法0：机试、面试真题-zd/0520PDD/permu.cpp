#include <bits/stdc++.h>
using namespace std;

int gmax, gmin;

void dfs(int cur, vector<int> & mm, int f)
{
    if(cur == mm.size()){
        gmax = max(f, gmax);
        gmin = min(f, gmin);
        return;
    }
    int tmp = f;
    for(int i = 1; i < mm.size(); i++){
        if(mm[i] == 0){
            mm[i] = 1;
            f = abs(tmp-i);
            dfs(cur+1, mm, f);
            mm[i] = 0;
        }
    }
}

int main()
{
    int N, n;
    cin >> N;
    while(N--)
    {
        gmax = numeric_limits<int>::min();
        gmin = numeric_limits<int>::max();
        cin >> n;
        vector<int> mm(n+1, 0);
        int f = 0;
        dfs(1, mm, f);
        cout << gmin << ' ' << gmax << endl;
    }
    return 0;
}