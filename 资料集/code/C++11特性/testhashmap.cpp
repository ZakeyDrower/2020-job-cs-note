#include<bits/stdc++.h>
using namespace std;

struct fun {
    
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }
}

int main()
{
    unordered_map<int,int> map;
    map[1] = 4;
    map[0] = 9;
    map[2] = 5;
    map[3] = 1;
    map[-1] = 10;
    sort(map.begin(), map.end(), fun);
    for(auto & p : map) {
        cout << p.first << ' ' << p.second <<endl;
    }
    return 0;
}