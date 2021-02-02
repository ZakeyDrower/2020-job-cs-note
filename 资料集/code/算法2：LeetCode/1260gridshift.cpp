#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    if(grid.size()==0 || grid[0].size()==0) return grid;
    int m = grid.size(), n = grid.front().size();
    k %= m*n;
    if(k == 0) return grid;
    vector<vector<int>> res(m, (vector<int>(n, 0)));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // int x = i*n+j;
            // int y = (x+k)%(m*n);
            // int ii = y/n, jj = y%n;
            // res[ii][jj] = grid[i][j];
            res[((i*n+j+k)%(m*n)) / n][((i*n+j+k)%(m*n)) % n] = grid[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> vec{
        vector<int>{1},
        vector<int>{2},
        vector<int>{3},
        vector<int>{4},
        vector<int>{7},
        vector<int>{6},
        vector<int>{5}
    };
    shiftGrid(vec, 23);
}