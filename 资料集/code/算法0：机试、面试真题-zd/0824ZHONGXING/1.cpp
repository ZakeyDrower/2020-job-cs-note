#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    int res = numeric_limits<int>::min();
    cin >> n;
    while(n--) {
        cin >> tmp;
        res = max(tmp, res);
    }
    cout << res << endl;
    return 0;
}