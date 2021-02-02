#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size()==0)
        return ;
    bool firCol = false;
    for(int i = 0; i < matrix.size(); ++ i){
        if(matrix[i][0]==0) firCol = true;
        for(int j = 1; j < matrix.front().size(); ++ j){
            if(matrix[i][j]==0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;   
            }
        }
    }

    for(int i = 1; i < matrix.size(); ++ i){
        for(int j = 1; j < matrix.front().size(); ++ j){
            if(matrix[0][j] == 0 ||  matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    // first row
    if(matrix[0][0]==0)
        for(int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;

    // first col
    if(firCol)
        for(int i = 0; i < matrix.size();i ++)
            if(firCol) matrix[i][0]=0;
}

int main() {
    vector<vector<int>> x({{1,1,1}, {0,1,2}});
    setZeroes(x);
    for(auto v : x)
        for (auto a : v) cout <<a << ' ';
        cout << endl;
}