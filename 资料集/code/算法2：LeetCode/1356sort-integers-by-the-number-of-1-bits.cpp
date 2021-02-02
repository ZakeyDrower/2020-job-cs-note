#include<bits/stdc++.h>
using namespace std;

int get(int x){
    int res = 0;
    while(x){
        res += x%2;
        x /= 2;
    }
    return res;
}

vector<int> sortByBits(vector<int> arr) {
    unordered_map<int, int> map;
    for(int i : arr) map[i] = get(i);
    sort(arr.begin(), arr.end(), [&](int a, int b){return map[a]==map[b] ? a<b : map[a] < map[b];});
    return arr;
}


int main()
{
    for(int i : sortByBits(vector<int> {0,1,2,3,4,5,6,7,8})){
        cout << i << ' ';
    }
    return 0;
}