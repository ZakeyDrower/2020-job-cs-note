#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int man_n,character_n;
        vector<pair<int,int>> men;
        vector<pair<int,int>> characters;
        cin >> man_n >> character_n;
        for(int i = 0;i < man_n;i++)
        {
            int t;
            cin >> t;
            men.push_back({i,t});
        }
        for(int i = 0;i < character_n;i++)
        {
            int t;
            cin >> t;
            characters.push_back({i,t});
        }
        sort(men.begin(),men.end(),[](pair<int,int> p1,pair<int,int> p2){return p1.second < p2.second;});
        sort(characters.begin(),characters.end(),[](pair<int,int> p1,pair<int,int> p2){return p1.second < p2.second;});
        for(int i = 0;i < man_n;i++)
        {
            int t = men[i].second;
            auto x = find_if(characters.begin(),characters.end(),[t](pair<int,int> p1){return p1.second >= t;});
            if(x == characters.end())
            {
                if(i == 0)
                    cout << -1;
                else
                    cout << " " << -1;
            }
            else
            {
                x->second = -1;
                if(i == 0)
                    cout << (x->first + 1);
                else
                    cout << " " << (x->first + 1);
            }
        }
        cout << endl;
    }
}