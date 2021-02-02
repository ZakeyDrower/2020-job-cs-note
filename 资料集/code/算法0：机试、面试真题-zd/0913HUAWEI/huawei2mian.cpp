/**
 * 给定矩阵，每个值代表一个细胞。1为活细胞，0为死细胞。细胞状态变化如下：
 * 活细胞：
 *      周围8个细胞里，活细胞数量小于2，则该细胞死亡；
 *      恰好有2个或者3个活细胞，该细胞存活；
 *      大于三个活细胞，该细胞死亡；
 * 死细胞：
 *      周围恰好三个活细胞，该细胞复活；
 *      否则继续保持死亡状态；
 * 求细胞矩阵的下一个状态。注：所有细胞的状态同时变化。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> addBordar(vector<vector<int>> b)
{
    vector<vector<int>> nb(b.size()+2, vector<int>(b[0].size()+2,0));
    for(int i = 0 ; i < b.size(); ++i) {
        for(int j = 0; j < b[0].size(); ++ j) {
            nb[i+1][j+1] = b[i][j];
        }
    }
    return nb;
}

int calscore(const vector<vector<int>> & b, const int & i, const int & j)
{
    return b[i-1][j-1]+b[i-1][j]+b[i-1][j+1] + b[i][j-1]+b[i][j+1] + b[i+1][j-1]+b[i+1][j]+b[i+1][j+1];
}

void game(vector<vector<int>> board)
{
    int m = board.size();
    int n = board[0].size();
    if(m*n==0) return;
    if(m==1 || n==1){
        for(auto  & v : board){
            for(auto & i : v){
                i = 0;
            }
        }
        return 0;
    }

    vector<vector<int>> nb = addBordar(board);
    vector<vector<int>> score(nb.size(), vector<int>(nb[0].size()); // score table
    for(int i = 1; i < nb.size()-1; ++ i) {
        for (int j = 1; j < nb[0].size()-1; ++j) {
            score[i][j] = calscore(nb, i, j);
        }
    }
    for(int i = 1; i < nb.size()-1; ++ i){
        for (int j = 1; j < nb[0].size()-1; ++j) {
            nb[i][j] = board[i][j] == 1 ? (
                score[i][j] < 2 ? 0 : (
                    score[i][j] > 3 ? 0 : 1;
                )
            ) : (
                score[i][j] == 3 ? 0 : // 问：死细胞怎么判定的来着
            )
        }
    }

    // print new board
    for(int i = 1; i < nb.size()-1; ++i){
        for(int j = 1; j < nb[0].size()-1; ++ j) {
            cout << nb[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> data = {
        {}
    }
}