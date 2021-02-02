#include <bits/stdc++.h>
using namespace std;

auto f = [](pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
};

int main()
{
    int T;
    int n, s;
    cin >> T;
    while (T--)
    {
        cin >> n >> s;
        int ori_s = s;
        vector<pair<int, int>> mosters;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            mosters.push_back({a, b});
        }
        sort(mosters.begin(), mosters.end(), f);
        int drop_thing = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (drop_thing > 0)
            {
                --drop_thing;
                drop_thing += mosters[i].second;
                ++res;
            }
            else
            {
                if (s > mosters[i].first)
                {
                    drop_thing += mosters[i].second;
                    s = s - mosters[i].first;
                    ++res;
                }
            }
        }
        if(drop_thing > 0)
        {
            res += ((n - res > drop_thing) ? drop_thing : n - res);
        }
        cout << res << " " << (ori_s - s) << endl;
    }
}
