#include "header.h"

bool carPooling(vector<vector<int>> & trips, int capacity)
{
    sort(trips.begin(), trips.end(), [] (vector<int> & a, vector<int> & b) {
        return a[1] < b[1];
    });
    int right = 0;
    int cur = 0;
    for(auto v : trips){
        if()
    }
}

int main()
{
    vector<vector<int>> vs {
        {3,4,5},
        {2,1,7},
        {9,2,3}
    };
    carPooling(vs, 3);
}