#include <bits/stdc++.h>
using namespace std;

/**
 * 最长递增子序列
 */
int maxLengthAscList(vector<int> arr)
{
    if(arr.size() < 2)
        return arr.size();
    
    vector<int> dp(arr.size(), 1);
    int res = 1;
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = i; j >= 0; j--)
        {
            dp[i] = arr[i] > arr[j] ?  max(dp[i], dp[j] + 1) : dp[i];
        }
        res = max(res, dp[i]);
    }

    return res;
}

/**
 * 0-1 backup
 */
int backbag_simple(int n, int w, vector<int> ws, vector<int> vs)
{
    if(w * n == 0)
        return 0;
    
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(j - ws[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i-1][j-ws[i-1]] + vs[i-1]
                );
            }
        }
    }

    return dp[n][w];
}

/**
 * 子集背包问题
 * 给定正数数组能否分割成和相等的两部分
 */
bool canPartition(vector<int> nums)
{
    int sum = 0;
    for(int i : nums)
        sum += i;
    if(sum%2 == 1)
        return false;
    sum /= 2;

    vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
    for(int i = 0; i <= nums.size(); i++)
        dp[i][0] = true;

    for(int i = 1; i <= nums.size(); i++)
    {
        for(int s = 1; s <= sum ; s++)
        {
            if(s - nums[i-1] < 0)
                continue;
            dp[i][s] = dp[i-1][s-nums[i-1]] || dp[i-1][s];
        }
        if(dp[i][sum])
            return true;
    }
    return false;
}
bool canPartition_compress(vector<int> nums)
{
    int sum = 0;
    for(int i : nums)
        sum += i;
    if(sum%2 == 1)
        return false;
    sum /= 2;

    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for(int i = 0; i < nums.size(); i++)
        for(int s = 1; s <= sum ; s++)
            if(s - nums[i-1] >= 0)
                dp[s] = dp[s-nums[i]] || dp[s];

    return dp[sum];
}

/**
 * 换零钱问题1：最少需要多少枚硬币
 */
int coinChange1(vector<int> coins, int t, unordered_map<int, int> & memo)
{
    if(memo.find(t) != memo.end())
        return memo[t];
    if(t == 0)
        return 0;
    if(t < 0)
        return -1;
    int res = numeric_limits<int>::max();
    for(int c : coins)
    {
        int subpro = coinChange1(coins, t-c, memo);
        if(subpro != -1)   
            res = min(res, subpro + 1);
    }
    memo[t] = memo[t] == numeric_limits<int>::max() ? -1 : res;
    return memo[t];
}
int coinChange12(vector<int> coins, int target)
{
    if(target < 0)  return -1;

    vector<int> dp(target + 1, target + 1);
    dp[0] = 0;
    for(int i = 1; i < target+1; i++)
    {
        for(int c : coins)
        {
            if(i - c < 0){
                continue;
            }
            dp[i] = c==i ? 1 : min(dp[i], dp[i-c] + 1);
        }
    }
    return (dp[target] == target+1) ? (-1) : dp[target];
}

/**
 * 凑硬币问题2
 * 一共有多少种凑出sum的方
 */
int coinChange2(vector<int> coins , int sum)
{
    if(sum < 0) return -1;
    vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, 0));

    for(vector<int> & v : dp) v[0] = 1;

    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(j-coins[i-1] >= 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back();
}
int coinChange22(vector<int> coins, int sum)
{
    if(sum < 0) return -1;

    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++)
        for(int j = 1; j <= sum; j++)
            if(j-coins[i-1] >= 0)
                dp[j] += dp[j-coins[i-1]];
    return dp.back();
}

/**
 * 最小编辑距离
 */
int minEditDist(string s1, string s2)
{
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i = 0; i <= s1.size(); i++) dp[i][0] = i;
    for(int j = 0; j <= s2.size(); j++) dp[0][j] = j;

    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
        }
    }
    return dp.back().back();
}

/**
 * 扔鸡蛋问题：简单版本
 */
int eddp(int K, int N, vector<vector<int>> & memo)
{
    if(N == 0) return 0;
    if(K == 1) return N;

    if(memo[K][N] != INT_MAX)
        return memo[K][N];

    int res = INT_MAX;
    // 这一段可以进阶
    for(int i = 1; i <= N; i ++)
    {
        res = min(
            res, 
            1 + max(
                eddp(K-1, i-1, memo),
                eddp(K, N-i, memo)
            ));
    }
    memo[K][N] = res;
    return res;
}
int eddp_dichotomy(int K, int N, vector<vector<int>> & memo)
{
    if(K == 1)  return N;
    if(N * K == 0) return 0;

    if(memo[K][N] != INT_MAX)
        return memo[K][N];
    
    int lo = 1, hi = N;
    int res = INT_MAX;
    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        int broken = eddp_dichotomy(K-1, mid - 1, memo) + 1;
        int notbro = eddp_dichotomy(K, N - mid, memo) + 1;
        if(broken > notbro){
            res = min(res, broken);
            hi = mid - 1;
        }else{
            res = min(res, notbro);
            lo = mid + 1;
        }
    }
    memo[K][N] = res;
    return res;
}
int eggDrop(int K, int N)
{
    vector<vector<int>> memo(K+1, vector<int>(N+1, INT_MAX));
    for(int i = 0; i <= N; i++) {memo[0][i] = 0, memo[1][i] = i;}
    for(int i = 0; i <= K; i++) {memo[i][0] = 0;}
    return eddp_dichotomy(K, N, memo);
}

/**
 * LCS:最长公共子序列
 */
int LCS(string s1, string s2)
{
    if(s1 == "" or s2 == "") return 0;
    
    class dp{
    private:
        string a{""};
        string b{""};
        vector<vector<int>> memo;
    public:
        dp(const string & s1, const string & s2) : 
            a(s1), 
            b(s2), 
            memo(vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, 0))) {}

        int run(int i, int j){
            if(j == 0 || i == 0) return 0;
            if(memo[i][j] != 0) return memo[i][j];

            if(a[i-1] == b[j-1])
                memo[i][j] = run(i-1, j-1) + 1;
            else
                memo[i][j] = max(run(i-1, j), run(i, j-1));
            return memo[i][j];
        }
    } dp(s1, s2);

    int res = dp.run(s1.size(), s2.size());
    return res;
}

/**
 * 最长回文子序列
 * Longest Reture Subsequence
 */
int LRS(string str)
{
    if(str.size() < 2) return str.size();

    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));

    for(int i = 0; i < str.size(); i ++)
        dp[i][i] = 1;

    for(int i = str.size()-2; i >= 0; i--)
    {
        for(int j = i+1; j < str.size(); j++)
        {
            if(str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }   

    return dp.front().back();
}

/**
 * 博弈问题：求先手-后手的分数差
 */
int cardGame(vector<int> cards)
{
    class p{
    public: 
        int fir{0};
        int sec{0};
        p(int fir, int sec) : fir(fir), sec(sec) {}
    };

    vector<vector<p>> dp(cards.size(), vector<p>(cards.size(), p(0,0)));
    for(int i = 0; i < cards.size(); i++) dp[i][i].fir = cards[i];

    for(int i = cards.size()-2; i >= 0; i--){
        for(int j = i+1; j < cards.size(); j++){
            dp[i][j].fir = max(
                cards[i] + dp[i+1][j].sec,
                dp[i][j-1].sec + cards[j]
            );
            dp[i][j].sec = min(
                dp[i+1][j].fir,
                dp[i][j-1].fir
            );
        }
    }
    return dp.front().back().fir - dp.front().back().sec;
    // 胜者分数
    // return max(dp.front().back().fir, dp.front().back().sec);
}

/**
 * 正则表达式匹配
 * Regular Expression Matching
 */
bool REM(string pat, string str)
{
    if(pat.size()*str.size()==0)
        return false;
    
    class rem{
    private:  
        string p;
        string s;
        vector<vector<int>> memo;
    public:  
        rem(string pat, string str) : 
                        p(pat), 
                        s(str), 
                        memo(vector<vector<int>>(p.size()+1, vector<int>(s.size()+1, -1))) {}

        bool dp(int i, int j){
            cout << i << ' ' << j <<endl;
            if(i == p.size() && j == s.size())
                return true;
            
            if(memo[i][j] != -1)
                return (bool) memo[i][j];
            // .
            bool first = p[i] == '.' || p[i] == s[j];
            // *
            if(i+1 < p.size() && p[i+1] == '*'){
                memo[i][j] = dp(i+2, j) ||
                        (first && dp(i, j+1));
            }else{
                memo[i][j] = first && dp(i+1, j+1); // first在前，防止i>p.size()
            }

            return (bool) memo[i][j];
        }
    } rem(pat, str);

    return rem.dp(0,0);
}

/**
 * 键盘输入N次，最多输入多少个A?
 * 可选输入：A，Ctrl+A，Ctrl+C，Ctrl+V
 */
int maxAAmount(int N)
{
    class maa{
    public:  
        int dp1(int n, int am, int cp){
            if(n < 4) return n + am;
            return max(
                dp1(n-1, am+1, cp),
                max(dp1(n-1, am+cp, cp),
                    dp1(n-2, am, am))
            );
        }
    } maa;

    return maa.dp1(N, 0, 0);
}

/**
 * KMP的DP解法
 */
int kmp(string txt, string pat)
{
    class KMP{
    private : 
        vector<vector<int>> dp;
        string pat;
    public :
        KMP(string pat){
            this->pat = pat;
            this->dp = vector<vector<int>>(pat.size(), vector<int>(256, 0));
            // 构建dp数组
            int x = 0;
            dp[0][pat[0]] = 1;
            for(int i = 1; i < dp.size(); i++){
                for(int j = 0; j < 256; j++)
                    dp[i][j] = dp[x][j];
                dp[i][pat[i]] = i+1;
                x = dp[x][pat[i]];
            }
        }
        
        int search(string txt){
            int res = 0;
            for(int i = 0; i < txt.size(); i++){
                if(res == pat.size())
                    return i - pat.size();
                res = dp[res][txt[i]];
            }
            return -1;
        }
    } kmpobj(pat);

    return kmpobj.search(txt);
}

/**
 * 区间调度问题
 * 最多不重合区间
 */
int intervalSchedule(vector<vector<int>> list)
{
    sort(list.begin(),list.end(),[](vector<int> a, vector<int> b){ return a[1] < b[1]; });
    int pre = 0;
    int count = 0;
    for(auto l : list){
        if(l[0] >= pre){
            pre = l[1];
            count ++;
        }
    }
    return count;
}

/**
 * 买股票专题
 */
int maxProfit(int k, vector<int> prices)
{
    if(prices.size() < 2)
        return 0;

    class maxProfit{
    private :
        int k{0};
        vector<int> ps;
        int n;
    public :
        maxProfit(int k, vector<int> prices) : k(k), ps(prices), n(prices.size()) {}

        int buyOnce(){
            int min = ps[0];
            int pro = 0;
            for(int i = 0; i < n; i ++)
                if(ps[i] < min) min = ps[i];
                else pro = max(pro, ps[i] - min);
            return pro;
        }

        // 买一次，用dp做
        int buyOnceDP(){
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + ps[i])
            // dp[i][1] = max(dp[i-1][1], dp[i-1][0][0] - ps[i]) = max(dp[i-1][1], -ps[i])
            vector<vector<int>> dp(n, vector<int>(2, 0));
            for(int i = 0; i < n; i++){
                if(i-1 == -1){
                    dp[i][0] = 0;
                    dp[i][1] = -ps[i];
                }else{
                    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + ps[i]);
                    dp[i][1] = max(dp[i-1][1], - ps[i]);
                }
            }
            return dp[n-1][0];
        }

        int buyOnceDP2(){
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + ps[i])
            // dp[i][1] = max(dp[i-1][1], dp[i-1][0][0] - ps[i]) = max(dp[i-1][1], -ps[i])
            int hold = INT_MIN, not_hold = 0;
            for(int i = 0; i < n; i++){
                not_hold = max(not_hold, hold + ps[i]);
                hold = max(hold, -ps[i]);
            }
            return not_hold;
        }

        int buyTwice(){
            int lmin = ps.front(), rmax = ps.back(), pro1 = 0, pro2 = 0;
            vector<int> pl(n, 0), pr(n, 0);
            for(int i = 0; i < n; i ++){
                if(ps[i] < lmin) lmin = ps[i];
                else pro1 = max(pro1, ps[i] - lmin);
                pl[i] = pro1;
                int j = n-1-i;
                if(ps[j] > rmax) rmax = ps[j];
                else pro2 = max(pro2, rmax - ps[j]);
                pr[j] = pro2;
            }

            int res = 0;
            for(int i = 0; i < n; i++)
                res = max(res, pl[i] + pr[i]);
            return res;
        }

        int buyTwiceDP(){
            vector<vector<vector<int>>> dp(
                n, vector<vector<int>>( 3, vector<int>(2, 0))
            );
            for(int i = 0; i < n; i++) { dp[i][0][0] = 0, dp[i][0][1] = INT_MIN;}
            for(int i = 0; i < n; i++){
                for(int k = 1; k <= 2; k++){
                    if(i-1 == -1){
                        dp[i][k][0] = 0;
                        dp[i][k][1] = - ps[i];
                    }else{
                        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + ps[i]);
                        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - ps[i]);
                    }
                }
            }
            return dp[n-1][2][0];
        }

        int buyKtimesDP(int k){
            vector<vector<vector<int>>> dp(
                n, vector<vector<int>>(k+1, vector<int>(2, 0))
            );
            for(int i = 0; i < n; i++) dp[i][0][1] = INT_MIN;
            for(int i = 0; i < n; i++){
                for(int j = 1; j <= k; j++){
                    if(i-1 == -1){
                        dp[i][j][0] = 0;
                        dp[i][j][1] = -ps[i];
                    }else{
                        dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + ps[i]);
                        dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - ps[i]);
                    }
                }
            }
            return dp[n-1][k][0];
        }

        int buyInfinity(){
            int res = 0;
            for(int i = 1; i < n; i++)
                res += (ps[i]>ps[i-1]) ? ps[i]-ps[i-1] : 0;
            return res;
        }

        int buyKtimesDP_SpaceCompressed(int k){
            vector<vector<int>> dp(k+1, vector<int>(2, 0));
            dp[0][1] = INT_MIN;
            for(int i = 0; i < n; i++){
                for(int j = 1; j <= k; j++){
                    if(i-1 == -1){
                        dp[j][0] = 0;
                        dp[j][1] = -ps[i];
                    }else{
                        dp[j][0] = max(dp[j][0], dp[j][1] + ps[i]);
                        dp[j][1] = max(dp[j][1], dp[j-1][0] - ps[i]);
                    }
                }
            }
            return dp[k][0];
        }
    } mpc(k, prices);

    cout << mpc.buyOnce() << "  " << mpc.buyOnceDP() << "  " << mpc.buyKtimesDP(1) <<endl;
    cout << mpc.buyTwice() << "  " << mpc.buyTwiceDP() << "  " << mpc.buyKtimesDP(2) <<endl;
    cout << mpc.buyInfinity() << endl;
    return 0;
}

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
void houserobber(vector<int> houses)
{
    class HB{
    private :
        vector<int> hs;
        int n;
        unordered_map<int, int> memo1;
    public :
        HB(vector<int> houses) : hs(houses), n(houses.size()) {}

        int hb1(int i)
        {
            if(i >= n) return 0;

            if(memo1.find(i) != memo1.end())
                return memo1[i];
            memo1[i] = max(hb1(i+1), hs[i] + hb1(i+2));
            return memo1[i];
        }
        int hb1()
        {
            vector<int> dp(n, 0);
            dp[0] = hs[0], dp[1] = max(hs[0], hs[1]);
            for(int i = 2; i < n; i++)
                dp[i] = max(dp[i-2] + hs[i] , dp[i-1]);
            return dp.back();
        }
        int hb1_O1()
        {
            int i_2 = hs[0], i_1 = max(hs[0], hs[1]);
            for(int i = 2; i < n; i++){
                int tmp = i_1;
                i_1 = max(i_2 + hs[i], i_1);
                i_2 = tmp;
            }
            return i_1;
        }

        // 房子成环形
        int subhb2(int l, int r)
        {
            if(l > r) return 0;
            if(l == r) return hs[l];
            int i_2 = hs[l], i_1 = max(hs[l], hs[l+1]);
            for(int i = l+2; i < r; i++){
                int tmp = i_1;
                i_1 = max(i_2 + hs[i], i_1);
                i_2 = tmp;
            }
            return i_1;
        }
        int hb2(){
            return max(subhb2(0, n-1), subhb2(1, n));
        }

        // 树形robber
        pair<int, int> rob(TreeNode * root)
        {
            if(root == nullptr)
                return pair<int,int> {0,0};
            pair<int,int> left = rob(root->left);
            pair<int,int> right = rob(root->right);
            // do
            int doit = root->val + left.first + right.first;
            // not do
            int notdo = max(left.second, left.first) + max(right.first, right.second);

            return pair<int,int>{notdo, doit};
        }

        int hsTree(TreeNode * root)
        {
            pair<int, int> res = rob(root);
            return max(res.first, res.second);
        }
    } robber(houses);

    cout << robber.hb1(0) << ' ' << robber.hb1() << ' ' << robber.hb1_O1() << endl;
}

int main()
{
    houserobber(vector<int>{3,0,1,2,1,4,1,2});
}