#include<bits/stdc++.h>
using namespace std;

struct point {
    int x;
    int y;
    point(int i, int j): x(i), y(j) {};
};

int cal(const vector<point> & ps, const point p) {
    int path = 0;
    for(const point & i : ps) {
        path += abs(i.x-p.x) + abs(i.y-p.y);
    }
    return path;
}

point findbest(const vector<point> & ps, const vector<point> & as) {
    int min_path = numeric_limits<int>::max();
    point res = as[0];
    for(const point & p: as) {
        int cur = cal(ps, p);
        if(cur < min_path) {
            min_path = cur;
            res = p;
        }
    }
    return res;
}

int main()
{
    int n, m;
    vector<point> ps;
    vector<point> as;
    cin >> n >> m;
    int x, y;
    while(n--){
        cin >> x >> y;
        ps.push_back(point(x, y));
    }
    while(m--) {
        cin >> x >> y;
        as.push_back(point(x, y));
    }
    point res = findbest(ps, as);
    cout << res.x << ' ' << res.y << endl;
    return 0;
}