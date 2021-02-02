#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid)
{
    // reture
    if(obstacleGrid.size() == 0 || obstacleGrid.front().size()==0) return 0;
    if(obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) return 0;
    // dp table
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid.front().size(), 1));
    // init
    for(int i = 1; i < dp.size(); i++) dp[i][0] = obstacleGrid[i][0]==1 ? 0 : dp[i-1][0];
    for(int i = 1; i < dp[0].size(); i++) dp[0][i] = obstacleGrid[0][i]==1 ? 0 : dp[0][i-1];
    // solution
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else
                dp[i][j] = (obstacleGrid[i-1][j]==1 ? 0 : dp[i-1][j]) + 
                            (obstacleGrid[i][j-1]==1 ? 0 : dp[i][j-1]);
        }
    }
    return dp.back().back();
}