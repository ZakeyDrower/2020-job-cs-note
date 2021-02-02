#include<bits/stdc++.h>
using namespace std;
int main()
{
    int life;
    int N;
    cin >> N >> life;
    unordered_map<int,int> map;
    for(int i = 0;i < N;i++)
    {
        int t;
        cin >> t;
        map[t]++;
    }
    vector<long long> dp(life+1, 0);
    dp[0] = 1;
    for(int i = 1;i <= life + 1;i++)
    {
        for(auto ite = map.begin();ite != map.end();ite++)
        {
            if(ite->first <= i)
            {
                dp[i] = dp[i] + dp[i-ite->first] * ite->second;
                dp[i] %= 1000000007;
            }
        }
    }
    long long res = dp[life];
    cout << res << endl;
    return 0;
}