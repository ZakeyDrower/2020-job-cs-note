#include <bits/stdc++.h>
using namespace std;

// print vector
void pvec(vector<int> v)
{
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}

// reorder arr by odevity
void reOrderArray(vector<int> &array)
{
    vector<int> a;
    vector<int> b;
    for (int x : array)
    {
        if (!(x % 2))
            b.push_back(x);
        else
            a.push_back(x);
    }
    array.clear();
    array.insert(array.end(), a.begin(), a.end());
    array.insert(array.end(), b.begin(), b.end());
}

// print matrix in clockwise
vector<int> PrintMatrix(vector<vector<int>> matrix)
{
    char order = 't';
    vector<int> vec{};
    while (matrix.size() != 0 && matrix[0].size() != 0)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        if (order == 't')
        {
            for (int x : matrix.front())
                vec.push_back(x);
            matrix.erase(matrix.begin());
            order = 'r';
        }
        else if (order == 'r')
        {
            for (int i = 0; i < M; i++)
            {
                vec.push_back(matrix[i][N - 1]);
                matrix[i].erase(matrix[i].end() - 1);
            }
            order = 'b';
        }
        else if (order == 'b')
        {
            for (int i = N - 1; i >= 0; i--)
            {
                vec.push_back(matrix[M - 1][i]);
            }
            matrix.erase(matrix.end() - 1);
            order = 'l';
        }
        else if (order == 'l')
        {
            for (int i = M - 1; i >= 0; i--)
            {
                vec.push_back(matrix[i][0]);
                matrix[i].erase(matrix[i].begin());
            }
            order = 't';
        }
    }

    return vec;
}

int vectoint(vector<int> vec)
{
    string str = "";
    for (int i : vec)
    {
        str += to_string(i);
    }
    return std::stoi(str);
}

string PrintMinNumber_outofrange(vector<int> numbers)
{
    if (numbers.size() == 0)
        return nullptr;

    sort(numbers.begin(), numbers.end());
    int min = 0x7fffffff;
    do
    {
        int cur = vectoint(numbers);
        min = min < cur ? min : cur;
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    return to_string(min);
}

bool compnum(int num1, int num2)
{
    string s1 = to_string(num1), s2 = to_string(num2);
    int n1 = s1.size(), n2 = s2.size();
    int i = 0;
    while (i < n1 && i < n2)
    {
        if (s1[i] > s2[i])
            return false;
        i++;
    }
    return true;
}

string PrintMinNumber(vector<int> numbers)
{
    if (numbers.size() == 0)
        return "";

    sort(numbers.begin(), numbers.end(), [](int a, int b) { return compnum(a, b); });
    string res = "";
    for (int i : numbers)
        res += to_string(i);

    return res;
}

long long calInvNum(vector<int> &data, vector<int> &copy, int start, int end)
{
    if (start == end)
    {
        //copy[start] = data[start];
        return 0;
    }

    int cut = (start + end) / 2;
    long long left = calInvNum(copy, data, start, cut);
    long long right = calInvNum(copy, data, cut + 1, end);
    long long cur = 0, i = cut, j = end, k = end;
    while (i >= start && j >= cut + 1)
    {
        if (data[i] > data[j])
        {
            cur += j - cut;
            copy[k--] = data[i--];
        }
        else
        {
            copy[k--] = data[j--];
        }
    }
    while (i >= start)
        copy[k--] = data[i--];
    while (j >= cut + 1)
        copy[k--] = data[j--];
    return left + right + cur;
}

int InversePairs(vector<int> data)
{
    if (data.size() < 2)
        return 0;

    vector<int> copy(data);
    long long num = calInvNum(data, copy, 0, data.size() - 1);
    return num % 1000000007;
}

int GetNumberOfK(vector<int> data, int k)
{
    if (data.size() == 0)
        return 0;
    int l = 0, r = data.size() - 1, m = (l + r) / 2;
    int res = 0;
    while (l <= r)
    {
        if (k == data[m])
        {
            res = 1;
            break;
        }
        else if (k < data[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = (l + r) / 2;
    }
    if (res != 0)
    {
        int i = m, j = m;
        while (data[--i] == k && i >= 0)
            res++;
        while (data[++j] == k && k <= data.size())
            res++;
    }
    return res;
}

vector<vector<int>> FindContinuousSequence(int sum)
{
    if (sum < 3)
        return vector<vector<int>>{};
    int cs = 3;
    vector<int> vec{1, 2};
    vector<vector<int>> res;
    while (vec.front() < sum / 2 + 1)
    {
        if (cs == sum)
        {
            res.push_back(vec);
            vec.push_back(vec.back() + 1);
            cs += vec.back();
        }
        else if (cs < sum)
        {
            vec.push_back(vec.back() + 1);
            cs += vec.back();
        }
        else if (cs > sum)
        {
            cs -= vec.front();
            vec.erase(vec.begin());
        }
    }
    return res;
}

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    int i = 0, j = array.size() - 1;
    int r1 = sum, r2 = sum;
    while (i <= j)
    {
        if (array[i] + array[j] == sum)
        {
            if (array[i] * array[j] < r1 * r2)
                r1 = array[i], r2 = array[j];
            i++, j--;
        }
        else if (array[i] + array[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if (r1 == sum)
        return vector<int>{};
    else
        return vector<int>{r1, r2};
}

string LeftRotatedString(string str, int n)
{
    n %= str.size();
    return string(str.begin() + n, str.end()) + string(str.begin(), str.begin() + n);
}

string ReverseSentence(string str)
{
    if (str == "")
        return str;

    int l = 0, r = 1;
    while (l < r && l < str.size())
    {
        while (!(str[r] == ' ' || str[r] == '\0'))
            r++;
        reverse(str.begin() + l, str.begin() + r);
        l = r + 1;
        r = l + 1;
    }
    reverse(str.begin(), str.end());
    return str;
}

bool IsContinuous(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    int cz = 0;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] == 0)
        {
            cz++;
        }
        else
        {
            if (numbers[i + 1] == numbers[i])
                return false;
            cz -= numbers[i + 1] - numbers[i] - 1;
        }
        if (cz < 0)
            return false;
    }
    return true;
}

int StrToInt(string str)
{
    if (str == "")
        return 0;
    int a = 0, f = 1, t = int('1') - 1;
    for (char c : str)
    {
        if (c == '-')
        {
            f = -1;
            continue;
        }
        if (c == '+')
        {
            continue;
        }
        if (c < '0' || c > '9')
            return 0;
        a *= 10;
        a += int(c) - t;
    }
    if (a * f >= (signed int)0x80000000 && a * f <= 0x7fffffff)
        return a * f;
    else
        return 0;
}

bool duplicate(int numbers[], int length, int *duplication)
{
    if (length <= 0)
        return false;
    int *p = numbers;
    bool found = false;
    unordered_map<int, int> map;
    while (p != numbers + length)
    {
        if (*p < 0 || *p >= length)
        {
            break;
        }
        if (map[*p] == 1 && !found)
        {
            duplication[0] = *p;
            found = true;
        }
        else
            map[*p] += 1;
        p++;
    }
    return (p == numbers + length && found) ? true : false;
}

vector<int> multiply(const vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return vector<int>{};
    vector<int> b1(n, 1);
    vector<int> b2(n, 1);
    vector<int> res(n);
    for (int i = 1; i < n; i++)
    {
        b1[i] = b1[i - 1] * A[i - 1];
        b2[n - 1 - i] = b2[n - i] * A[n - i];
    }
    for (int i = 0; i < n; i++)
        res[i] = b1[i] * b2[i];
    return res;
}

// 递归解法
bool match(char *str, char *pat)
{
    // 终止条件
    if (*str == '\0' && *pat == '\0')
    {
        return true;
    }
    // 如果下一个不是*，必须先匹配当前char
    if (*pat != '\0' && *(pat + 1) != '*')
    {
        // cur match
        if ((*pat == '.' && *str != '\0') || (*pat == *str))
        {
            if (match(str + 1, pat + 1))
                return true;
        }
        return false;
    }
    // 如果下一个是*,可以不匹配当前项，直接跳过该段pat。或者匹配当前项，str+1
    if (*pat != '\0' && *(pat + 1) == '*')
    {
        if (match(str, pat + 2))
            return true;
        // cur match
        if ((*pat == '.' && *str != '\0') || (*pat == *str)) // 此处不要求*str不为'\0'
        {
            if (match(str + 1, pat) || match(str + 1, pat + 2))
                return true;
        }
    }
    return false;
}

// dp 解法
int getLen(char *s)
{
    char *p = s;
    int i = 0;
    while (*p != '\0')
    {
        i++;
        p++;
    }
    return i;
}
vector<vector<bool>> initdpmat(char *s, char *e, int x, int y)
{
    vector<vector<bool>> dp(x + 1, vector<bool>(y + 1));
    dp[x][y] = true;
    for (int j = y - 2; j > -1; j -= 2)
    {
        if (e[j] != '*' && e[j + 1] == '*')
            dp[x][j] = true;
        else
            break;
    }
    if (x > 0 && y > 0)
    {
        if (e[y - 1] == '.' || s[x - 1] == e[y - 1])
            dp[x - 1][y - 1] = true;
    }
    return dp;
}
bool matchdp(char *str, char *pat)
{
    int x = getLen(str);
    int y = getLen(pat);
    vector<vector<bool>> dp = initdpmat(str, pat, x, y);
    for (int i = x - 1; i > -1; i--)
    {
        for (int j = y - 2; j > -1; j--)
        {
            if (pat[j + 1] != '*')
            {
                dp[i][j] = (str[i] == pat[j] || pat[j] == '.') && dp[i + 1][j + 1];
            }
            else
            { // pat[j+1] == '*'
                int si = i;
                while (si != x && (str[si] == pat[j] || pat[j] == '.'))
                {
                    if (dp[si][j + 2])
                    {
                        dp[i][j] = true;
                        break;
                    }
                    si++;
                }
                if (dp[i][j] != true)
                {
                    dp[i][j] = dp[si][j + 2];
                }
            }
        }
    }

    return dp[0][0];
}

// 滑动窗口的最大值
vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (num.size() == 0 || size <= 0 || size > num.size())
        return vector<int>{};

    vector<int> res;
    auto comp = [](pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    int i = 0, j = 0;
    while (j < size && j < num.size())
    {
        q.push(make_pair(num[j], j));
        j++;
    }
    res.push_back(q.top().first);
    while (j < num.size())
    {
        q.push(make_pair(num[j], j));
        while (q.top().second < i + 1 && q.size() > size)
        {
            q.pop();
        }
        res.push_back(q.top().first);
        j++, i++;
    }
    return res;
}

template <typename T>
T gssmerge(vector<T> &vec, int l, int m, int r)
{
    vector<T> L(vec.begin() + l, vec.begin() + m + 1);
    vector<T> R(vec.begin() + m + 1, vec.begin() + r + 1);
    L.insert(L.end(), numeric_limits<T>::max());
    R.insert(R.end(), numeric_limits<T>::max());
    T sum = 0;
    int i = 0, j = 0;
    for (int k = l; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            sum += L[i] * (R.size() - 1 - j);
            vec[k] = L[i++];
        }
        else
        {
            vec[k] = R[j++];
        }
    }
    return sum;
}

template <typename T>
T gssfunc(vector<T> &vec, int l, int r)
{
    if (l == r)
        return 0;
    int m = (l + r) / 2;
    return gssfunc(vec, l, m) + gssfunc(vec, m + 1, r) + gssmerge(vec, l, m, r);
}

// 小和（类似于逆序数那样的概念，改写归并排序）
template <typename T>
T getSmallSum(vector<T> vec)
{
    if (vec.size() == 0)
        return 0;
    return gssfunc(vec, 0, vec.size() - 1);
}

// 最大子数组和
template <typename T>
T maxSum(vector<T> vec)
{
    if (vec.size() == 0)
        return 0;
    T cur = 0, sum = numeric_limits<T>::min();
    for (T t : vec)
    {
        cur += t;
        sum = max(sum, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return sum;
}

// 最大子数组乘积
template <typename T>
T maxMulti(vector<T> vec)
{
    if (vec.size() == 0)
        return;
    T res = numeric_limits<T>::min(), max = vec[0], min = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        max = max(max(max * vec[i], min * vec[i]), vec[i]);
        min = min(min(max * vec[i], min * vec[i]), vec[i]);

        res = max(max, res);
    }
    return max;
}

// 环形山头，一共有多少个对可以交流。思路：单调栈。
int nextIndex(const vector<int> &v, int curIndex)
{
    return curIndex + 1 < v.size() ? curIndex + 1 : 0;
}
long getInterComCount(pair<int, int> p)
{
    return p.second == 1 ? 0 : (p.second * (p.second - 1) / 2);
}
long communications(vector<int> v)
{
    if (v.size() == 0)
        return 0;
    int maxIndex = 0;
    // 找到（第一个）最大的数字的下标
    for (int i = 0; i < v.size(); i++)
        maxIndex = v[maxIndex] >= v[i] ? maxIndex : i;

    stack<pair<int, int>> s;
    s.push(make_pair(v[maxIndex], 1));
    int ci = nextIndex(v, maxIndex); // current index
    long count = 0;
    // 按照单调栈过程压栈，过程中结算pop出去的部分
    while (ci != maxIndex)
    {
        while (!s.empty() && s.top().first < v[ci])
        {
            count += getInterComCount(s.top()) + s.top().second * 2;
            s.pop();
        }
        if (!s.empty() && s.top().first == v[ci])
            s.top().second++;
        else
            s.push(make_pair(v[ci], 1));
        ci = nextIndex(v, ci);
    }
    // 全部压栈完成，结算栈中剩余部分
    while (!s.empty())
    {
        pair<int, int> cp = s.top(); // current pop
        s.pop();
        count += getInterComCount(cp);
        if (!s.empty())
        {
            count += cp.second;
            if (s.size() > 1)
            { // 是：cp至少为栈的倒数第三个数。否：cp为倒数第二个数（不可能是最后一个数）
                count += cp.second;
            }
            else
            { // 此时，栈中只剩下最大值及其个数组成的pair
                count += s.top().second > 1 ? cp.second : 0;
            }
        }
    }
    return count;
}

// 题目：一个矩阵，0表示海，1表示导，相连的1位同一个岛，求一共有几个岛。
void influenceIsland(vector<vector<int>> &v, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || v[i][j] != 1)
        return;
    v[i][j] = 2;
    influenceIsland(v, i + 1, j, m, n);
    influenceIsland(v, i - 1, j, m, n);
    influenceIsland(v, i, j + 1, m, n);
    influenceIsland(v, i, j - 1, m, n);
}
int countIsland(vector<vector<int>> a)
{
    if (a.size() == 0)
        return 0;

    int count = 0;
    int m = a.size(), n = a[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                count++;
                influenceIsland(a, i, j, m, n);
            }
        }
    }
    return count;
}
// 进阶版：多线程编程。并行计算解决该问题。
// Targin 算法

// 水槽问题
template <typename T>
T sinkSolution(vector<T> arr)
{
    if (arr.size() < 3)
        return T();
    T ml = arr.front(), mr = arr.back();
    int l = 1, r = arr.size() - 2;
    T res = T();
    while (l <= r)
    {
        if (ml < mr)
        {
            res += (arr[l] < ml) ? (ml - arr[l]) : 0;
            ml = std::max(ml, arr[l++]);
        }
        else
        {
            res += (arr[r] < mr) ? (mr - arr[r]) : 0;
            mr = std::max(mr, arr[r--]);
        }
    }
    return res;
}

// 求两个不相交子数组的最大累加和
template <typename T>
T getMaxSumOf2SubArr(vector<T> v)
{
    if (v.size() < 3)
        return T();
    vector<T> rec(v.size(), 0);
    T max = numeric_limits<T>::min(), cur = 0;
    for (int i = v.size() - 1; i > 0; i++)
    {
        cur += v[i];
        max = max(max, cur);
        rec[i] = max;
        cur = cur < 0 ? 0 : cur;
    }
    T res = numeric_limits<T>::min();
    max = numeric_limits<T>::min(), cur = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cur += v[i];
        max = max(max, cur);
        res = max(res, max + rec[i + 1]);
        cur = cur < 0 ? 0 : cur;
    }
    return res;
}

// 子矩阵最大和
template <typename T>
void updateHelp(const vector<vector<T>> &mat, vector<T> &help, const int &i, const bool &trans)
{
    for (int j = 0; j < std::max(mat.size(), mat.front().size()); j++)
        help[j] += trans ? mat[j][i] : mat[i][j];
}
template <typename T>
T maxSunOfMatrix(vector<vector<T>> mat)
{
    int M = mat.size(), N = mat.front().size();
    if (M == 0 || N == 0)
        return T();

    T res = numeric_limits<T>::min();
    bool trans = M > N ? true : false;

    for (int begin = 0; begin < std::min(M, N); begin++)
    {
        vector<T> help = trans ? vector<T>(M) : vector<T>(N);
        for (int i = begin; i < std::min(M, N); i++)
        {
            //T max = numeric_limits<T>::min(); //这个局部最优可以去掉
            T cur = 0;
            updateHelp(mat, help, i, trans);
            for (int j = 0; j < help.size(); j++)
            {
                cur += help[j];
                //max = std::max(max, cur);
                res = std::max(res, cur);
                cur = cur < 0 ? 0 : cur;
            }
        }
    }
    return res;
}

template <typename T>
T getMaxRect(const vector<T> &v)
{
    if (v.size() == 0)
        return T();
    stack<int> s; // storage index
    T max = numeric_limits<T>::min();
    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[i] <= v[s.top()])
        {
            T h = v[s.top()];
            s.pop();
            int j = s.empty() ? -1 : s.top();
            T cur = (i - j - 1) * h;
            max = std::max(max, cur);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        T h = v[s.top()];
        s.pop();
        int j = s.empty() ? -1 : s.top();
        T cur = (v.size() - j - 1) * h;
        max = std::max(max, cur);
    }
    return max;
}
int countMaxRectOf1(const vector<vector<int>> &mat)
{
    if (mat.size() == 0 || mat[0].size() == 0)
        return 0;

    int res = 0;
    vector<int> help(mat[0].size());
    for (vector<int> v : mat)
    {
        for (int i = 0; i < v.size(); i++)
            help[i] = v[i] == 1 ? help[i] + 1 : 0;
        res = max(res, getMaxRect(help));
    }
    return res;
}

/**
 * 给定数组arr和数字num，求有多少个子数组满足：
 * max(subarr) - min(subarr) <= num
 */
template <typename T>
T updateAndGetDequeFront(deque<int> &max, int i, const vector<T> &arr)
{
    while (!max.empty() && max.front() >= i)
        max.pop_front();
    return max.empty() ? T() : arr[max.front()];
}
template <typename T>
int getSubArrNumSatisfied(const vector<T> &arr, const T &num)
{
    if (arr.size() == 0)
        return 0;

    deque<int> maxq; // storage index
    deque<int> minq; // storage index
    int i = 0, j = 0;
    int res = 0;
    while (i < arr.size() && j < arr.size())
    {
        // 扩充队列
        while (j < arr.size() && updateAndGetDequeFront(maxq, i, arr) - updateAndGetDequeFront(minq, i, arr) <= num)
        {
            while (!maxq.empty() && arr[maxq.back()] <= arr[i])
                maxq.pop_back();
            maxq.push_back(j);
            while (!minq.empty() && arr[minq.back()] >= arr[i])
                minq.pop_back();
            minq.push_back(j);
            j++;
        }
        if (j >= arr.size())
        {
            res += (j - i + 1) * (j - i) / 2;
            break;
        }
        res += j - i;
        i++;
    }
    return res;
}


/**
 * 移动无限大棋盘上棋子的问题。
 * 返回的数组，res[i]表示使得i个棋子重叠的最小移动次数。
 */
vector<int> minOps(const vector<int> & x, const vector<int> & y )
{
    vector<int> res(x.size(), numeric_limits<int>::max());
    priority_queue<int> q;
    for(int i = 0; i < x.size(); i++)
    {
        for(int j = 0 ; j < y.size(); j++)
        {
            for(int k = 0; k < x.size(); k++)
                q.push(abs(x[k] - x[i]) + abs(y[k] - y[j]));
            int sum = 0;
            int resi = 0;
            while(!q.empty()){
                sum += q.top();
                res[resi] = min(res[resi], sum);
                q.pop();
                resi++;
            }
        }
    }
    return res;
}

/**
 * 最大的疯狂值（相邻两数差值之和）
 */
int maxMadNum(vector<int> a)
{
    sort(a.begin(), a.end());
    int i = 0, j = a.size()-1;
    int mad = a[j] - a[i];
    while(i < j){
        if(j-1 == i+1)
            mad += max(a[j] - a[j-1], a[i+1] - a[i]);
        else{
            mad += a[j-1] - a[i];
            mad += a[j] - a[i+1];
        }
        i++, j--;
    }
    
    return mad;
}

/**
 * 分金条，代价最小
 * 霍夫曼树，贪心，优先级队列（堆）
 */
int minCost(const vector<int>  & a)
{
    priority_queue<int> q;
    for(int i : a)
        q.push(i);
    int sum = 0;
    int cur;
    while(q.size() > 1)
    {
        cur = 0;
        cur += q.top(), q.pop();
        cur += q.top(), q.pop();
        sum += cur;
        q.push(cur);
    }
    return sum;
}

/**
 * 做k个任务，初始资金w，任务收益p，启动资金c，问最终的最大资金数是多少？
 * k,w,p[], c[]
 */



/**
 * 右上角没有点的点称为最大点（不存在i,j使得i>x&&j>y），求给定点集中所有最大点。
 * 输入点集，输出最大点集合。
 */


/**
 * 给定数组arr，求使得 f(sa) = min(sa)*sum(sa) 最大的子数组对应的 f(sa)。
 * 输入arr，输出最大值。
 */


/**
 * 调度问题。
 * 项目（Program）：index, pm, start, rank, cost
 * Rule 1 PM对项目实施优先度考虑：rank > cost > start
 * Rule 2 程序员接收项目并开发的优先度考虑：cost > program.pm
 * P个项目分配给N个PM，由M个程序员完成。
 * 
 * 需要注意：
 * A时刻时，程序员不能做start>A时刻的任务。
 * 
 * 问题分析：
 * 每个PM按照Rule 1组织一个优先级队列（堆），把所有堆的堆顶组成一个堆，并且该堆的组织方式为Rule 2.
 * 程序员（sde）的freetime单独维护为一个优先级队列。
 *      如果pro.start < heap,弹出堆顶，并+=pro.cost,后压入队列
 *      如果pro.start 大于所有的堆中元素。弹出堆中所有M个元素，向队列中压入M个pro.start
 * 所有的program按照start组织一个优先级队列。
 * 
 * 本题连同数据结构设计，代码200行左右。 
 * 这个题用优先级队列的优先级队列是不行的，必须自己写一个堆，深度的改。
 */


/**
 * 最长递增子序列（不连续）的长度
 * 一般方法 O(n2)
 * 优化：除了记录长度的辅助数组之外，添加ends[]数组。end[i]表示目前所有长度为i+1的子序列的最小结尾
 * 在ends数组上依赖二分查找，将时间复杂度优化到 O(NlogN)
 */


/**
 * 俄罗斯信封问题：包信封。
 * 信封w，h。w递增，h递减排序，找最大递增子序列。
 */


/**
 * 原始问：出现次数top K的k个数。
 * 原始解：哈希表+小根堆。O(NlogN)
 * 
 * 进阶问：数组（字符串）变为动态（类似于流的概念），随时加入新数据，并根据加入后的情况随时打印次数最多的前K个数。
 *        要求：add复杂度O(logK)，printTopK复杂度O(k)
 * 数据结构：一个map存词频，一个大小为k的小根堆，一个map存词在堆中的位置（不再堆中置-1）
 */

/**
 * 正正数数组的最小不可组成和
 * 
 * 思路1：暴力递归，所有和存进set，得出最小最大，遍历set寻找最小不可组成和。时间复杂度O(2^n)
 * 思路2：空间换时间。类似于背包的策略，时空间复杂度：O(n*max)
 * 思路3：如果包含1，时间复杂度优化到O(nlogn)，除排序之外的复杂度是空间O(1)，时间O(n)
 */

/**
 * 京东：神奇数问题
 * 给定区间，求区间内神奇树数目。
 * 背包策略类似于上题的思路2.
 * 终止条件为：任意一行加到了sum/2，不用计算到最后一行
 * 空间可优化至O(1)。即只用一个1*82的数组。
 */



/**
 * 京东：KMP
 * 给定字符串s，请输出含有连续两个s的最短字符串，两数组可重叠。如给定aba，返回ababa。
 * 方法：改写KMP。（next数组部分）
 * return s + string(s.begin(), s.begin()+next[s.size()]);
 */

/**
 * 京东
 * 给定合法括号字符串s，每次移除最左边的（与任意），并保证移除后的s'依然为合法括号串。
 * 求一共有多少种移除方法？
 * 例：
 * ()()()() -> 1
 * (((()))) -> 4*3*2*1 = 24
 */

/**
 * 京东：Manacher
 * 给定字符串s，只能在s末尾添加字符串，求能使添加后的s'为回文串的最短值。
 * 解题：需要求以最后一个字符结尾的s的最长回文子串，再把不属于该串的前面的部分逆序后添加在s末尾。
 * 如：
 * abcdc -> abcdc ba
 * 解法：改写Manacher为，R扩到右边界事，就停。
 */


/**
 * 滴滴：数组划分异或为0
 * 
 */
int mostXORs0(vector<int> arr)
{
    if(arr.size() == 0)
        return 0;
    
    //int ans = numeric_limits<int>::min();
    vector<int> most(arr.size());
    int cur_xor = 0;

    map<int, int> map;
    map.insert(std::pair<int,int>(0,-1));
    
    for(int i = 0; i < arr.size(); i++)
    {
        cur_xor = cur_xor ^ arr[i];
        if(map.find(cur_xor) != map.end()){
            int pre = map[cur_xor];
            most[i] = pre==-1 ? 1 : most[pre] + 1;
            most[i] = std::max(most[i-1], most[i]);
        }else{
            most[i] = i==0 ? 0 : most[i-1];
        }
        map[cur_xor] = i;
        //ans = std::max(ans, most[i]);
    }
    //return ans;
    return most.back();
}

/**
 * 求数组(正负0）中和为k的最长子数组的长度
 * 
 */
int getMaxLengthOfSumK(vector<int> v, int k)
{
    if(v.size() == 0)
        return 0;

    map<int, int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;
    for(int i = 0; i <v.size(); i++)
    {
        sum += v[i];
        if(map.find(sum) == map.end()){
            map[sum] = i;
        }
        if(map.find(sum-k) != map.end()){
            len = std::max(len, i-map[sum-k]);
        }
    }
    return len;
}

/**
 * 上题数组改为正数数组
 */
int getMaxLengthOfSumKOfPositiveArr(vector<int> v, int k)
{
    if(v.size() == 0) 
        return 0;

    int sum=0;
    int l = 0, r = 0;
    int len = 0;
    while(r < v.size()){
        if(sum < k){
            sum += v[r++];
        }else if(sum == k){
            len = std::max(len, r-l+1);
            sum -= v[l++];
        }else{
            sum -= v[l++];
        }
    }
    return len;
}

/**
 * 上一题继续扩充，数组内和小于等于K的最大子数组长度
 */
int getMaxLengthOfSumK_levelUp(vector<int> v, int k)
{
    if(v.size() == 0)
        return 0;
    
    vector<int> min_sum(v.size());
    vector<int> min_sum_index(v.size());
    min_sum.back() = v.back();
    min_sum_index.back() = v.size() - 1;

    for(int i = v.size()-2; i >= 0; i++){
        min_sum[i] = min_sum[i+1] < 0 ? v[i] + min_sum[i+1] : v[i];
        min_sum_index[i] = min_sum[i+1] < 0 ? min_sum_index[i+1] : i;
    }

    int len = 0, l = 0, r = 0, sum = 0;
    // 不需要使用for循环挨个作为起点
    for(l = 0; l < v.size(); l++)
    {
        while(r < v.size() && sum + min_sum[r] <= k){
            sum += min_sum[r];
            r = min_sum_index[r+1];
        }
        len = std::max(len, r-l);
        if(r > l){  // 窗口内还有值，直接让sum减去l处的值
            sum -= v[l++];
        }else{  // 窗口大小为0，即，l和r重合了，重置窗口右侧r为l+1
            r = l+1;
        }
    }
    return len;
}

/**
 * 打印数组中出现次数大于N/K的数。
 * 如果不存在，输出错误信息。
 */
void printKMajor(vector<int> v, int k)
{
    if(k < 2){
        cout << "k is invalid." << endl;
        return ;
    }

    map<int, int> cands;
    for(int a : v){
        if(cands.find(a) != cands.end()){
            cands[a] += 1;
        }else if(cands.size() < k){
            cands[a] = 1;
        }else{
            // cands中所有cand的times减小1，如果减到了0，删除；
            vector<int> removeList;
            for(auto & p : cands){
                if(p.second == 1)
                    removeList.push_back(p.first);
                else
                    cands[p.first] = p.second - 1;
            }
            for(int del : removeList){
                cands.erase(del);
            }
        }
    }
    // 检查所有的cands是否都为目标值
    for(auto p : cands){
        cands[p.first] = 0;
    }
    for(int a : v){
        if(cands.find(a) != cands.end()){
            cands[a] += 1;
        }
    }
    bool printed = false;
    for(auto p : cands){
        if(p.second > v.size()/k){
            printed = true;
            cout << p.first << ' ';
        }
    }

    cout << (printed ? "" : "no such number") << endl;
}

/**
 * 设计一个结构，在O(1)时间内实现key的insert、delete、getRandom。
 */
template<class T>
class myHashSet{

private:
    map<T, int> ki;
    map<int, T> ik;
    int size{0};

public:
    myHashSet<T>(){};

    void insert(T key){
        if(ki.find(key) != ki.end())
            return;
        ki[key] = size;
        ik[size] = key;
        size ++;
    };

    void deletekey(T key){
        int delid = ki[key];
        T lastKey = ik[size-1];
        ik[delid] = lastKey;
        ki[lastKey] = delid;
        ik.erase(size-1);
        ki.erase(key);
        size--;
    };

    void printMemo(){
        cout << "size = " << size << endl;
        for(auto & p : ki){
            cout << p.first << " " << p.second << " " << ik[p.second] << endl;
        }
    }

    T getRandom(){
        return ik[rand()%size];
    }
};

/**
 * 求两个等长度排序树组的上中位数（即，两个长度为L的排序树组，求整体第L小的数）
 */
int getUpMedian(vector<int> a, vector<int> b)
{
    if(a.size()*b.size() == 0 || a.size() != b.size())
        return 0;
    
    int l1 = 0, r1 = a.size()-1, l2 = 0, r2 = b.size()-1;
    int m1 = 0, m2 = 0;
    int offset = 0;
    while(l1 < r1)
    {
        m1 = (l1 + r1) / 2, m2 = (l2 + r2) / 2;
        // 补正值，当数组长度为奇数，offset取0，从数组上来看是借了一个数；数组长度为偶数的时候，不用这样借，offset取1，下标更新的时候要+1避过已经访问过的mid
        offset = ((r1 - l1 + 1) & 1) ^ 1; 
        if(a[m1] > b[m2]){
            r1 = m1;
            l2 = m2 + offset;
        }else if(a[m1] < b[m2]){
            l1 = m1 + offset;
            r2 = m2;
        }else{
            return a[m1];
        }
    }
    return std::min(a[l1], b[l2]);
}

/**
 * 寻找两个排序树组中第k小的数
 */
bool invalid_argument_getUpMedian_2 = false;
bool invalid_argument_findKthNum = false;
int getUpMedian_2(vector<int> arr1, int left1, int right1, vector<int> arr2, int left2, int right2)
{
    if(right1 - left1 != right2 - left2 || right1 - left1 < 0){
        invalid_argument_getUpMedian_2 = true;
        return 0;
    }
    int mid1, mid2;
    int offset;
    while(left1 < right1){
        offset = ((right1 - left1 + 1) & 1) ^ 1;
        mid1 = (left1+right1)/2;
        mid2 = (left2+right2)/2;
        if(arr1[mid1] == arr2[mid2]){
            return arr1[mid1];
        }else if(arr1[mid1] > arr2[mid2]){
            right1 = mid1;
            left2 = mid2 + offset;
        }else{
            left1 = mid1 + offset;
            right2 = mid2;
        }
    }
    return std::min(arr1[left1], arr2[left2]);
}
int findKthNum(vector<int> arr1, vector<int> arr2, int k)
{
    if(arr1.size() == 0 || arr2.size() == 0 || k < 1 || k > arr1.size()+arr2.size()){
        invalid_argument_findKthNum = true;
        return 0;
    }
    vector<int> shortarr = arr1.size() < arr2.size() ? arr1 : arr2;
    vector<int> longarr = arr1.size() < arr2.size() ? arr2 : arr1;
    int m = shortarr.size();
    int n = longarr.size();
    if(k <= m){
        return getUpMedian_2(shortarr, 0, k-1, longarr, 0, k-1);
    }
    if(k > n){
        if(shortarr[k-n-1] > longarr.back())
            return shortarr[k-n-1];
        if(longarr[k-m-1] > shortarr.back())
            return longarr[k-m-1];
        return getUpMedian_2(shortarr, k-n, m-1, longarr, k-m, n-1);
    }
    if(longarr[k-m-1] > shortarr.back())
        return longarr[k-m-1];
    else
        return getUpMedian_2(shortarr, 0, m-1, longarr, k-m, k-1);
}

/**
 * 最小包含子串
 */
int getMinLength(string str1, string str2)
{
    if(str1.size() == 0 || str2.size() == 0 || str1.size() < str2.size())
        return 0;
    
    map<char, int> map;
    int all = 0;

    for(char c : str2){
        map[c] ++;
        all ++;
    }

    int minlen = numeric_limits<int>::max();
    int L = 0, R = 0;
    while(R < str1.size()){
        // slide R
        while(R < str1.size() && all > 0){
            if(map[str1[R]]-- > 0)
                all--;
            R++;
        }
        // slide L
        while(L < R && all == 0){
            L++;
            if(map.find(str1[L]) != map.end() && map[str1[L]] == 0){
                all++;
                minlen = std::min(minlen, R - L + 2);
            }
        }
    }

    return minlen == numeric_limits<int>::max() ? 0 : minlen;
}
int getMinLength1(string s1, string s2)
{
    if(s1.length()*s2.length() == 0 || s1.length() < s2.length())
        return 0;
    
    int l = 0, r = 0, all = s2.length(), minlen = numeric_limits<int>::max();
    map<char, int> map;
    
    for(char c : s2) map[c]++;

    while(r < s1.length()){
        if(map[s1[r]]-- > 0) all--;
        if(all == 0){
            while(map[s1[l]] < 0){
                map[s1[l++]]++;
            }
            minlen = std::min(minlen, r-l+1);
            map[s1[l++]]++;
            all++;
        }
        r++;
    }
    return minlen == numeric_limits<int>::max() ? 0 : minlen;
}

/**
 * 完美洗牌
 * 傻瓜解O(n)省略，只写最优解时间O(n)，空间O(1)
 */
void shuffle(vector<int> & arr);
void shuffle(vector<int> & arr, int L, int R);
void shuffle_rotate(vector<int> & arr, int l, int m, int r);
void shuffle_cycle(vector<int> & arr, int l, int r, int k);
int shuffle_getNewIndex(int old_index, int len);

void shuffle(vector<int> & arr)
{
    if(arr.size() != 0 && (arr.size() & 1) == 0){
        shuffle(arr, 0, arr.size()-1);
    }
}

void shuffle(vector<int> & arr, int L, int R)
{
    if(L >= R)
        return;
    
    int cur_len = R-L+1;
    // 获取满足 3^k - 1==len 的最大k值。
    int k = (int)floor(log(cur_len+1)/log(3));
    int half = (int)(pow(3,k)-1)/2;
    int mid = (int)floor((R-L)/2);
    // 通过旋转调整出 3^k - 1 段位开头
    shuffle_rotate(arr, L+half, L+mid, L+mid+half);
    // 对调整好的部分，怼
    shuffle_cycle(arr, L, L+2*half-1, k);
    // 处理剩余部分
    shuffle(arr, L+2*half, R);
}

void shuffle_cycle(vector<int> & arr, int L, int R, int K)
{
    int len = R - L + 1;
    for(int k = 0; k < K; k++){
        int cur_start = pow(3,k) - 1;
        int old_id = cur_start;
        int new_id = shuffle_getNewIndex(old_id, len);
        int pre = arr[L + old_id];
        while(new_id != cur_start){
            // 更新值
            int temp = arr[L + new_id];
            arr[L + new_id] = pre;
            pre = temp;
            // 寻找新下标
            old_id = new_id;
            new_id = shuffle_getNewIndex(old_id, len);
        }
        arr[L + cur_start] = pre;
    }
}

int shuffle_getNewIndex(int old_index, int len)
{
    if(old_index < len/2)
        return 2*old_index + 1;
    return 2*(old_index - len/2);
}

void shuffle_rotate(vector<int> & arr, int l, int m, int r)
{
    reverse(arr.begin() + l, arr.begin() + m + 1);
    reverse(arr.begin() + m + 1, arr.begin() + r + 1);
    reverse(arr.begin() + l, arr.begin() + r + 1);
}

/**
 * 分糖果问题：原问题
 */
int candy1(vector<int> arr);
int nextMinIndex1(vector<int> arr, int start);
int rightCands(vector<int> arr, int left, int right);

int candy1(vector<int> arr)
{
    if(arr.size() == 0)
        return 0;
    
    int index = nextMinIndex1(arr, 0);      // 下一个（第一个）下坡坡底
    int res = rightCands(arr, 0, index++);  // 总糖果数
    int lbase = 1;                          // 左坡（上坡）坡顶糖果数量
    int next = 0;                           // 用于下标向下坡坡底跳跃
    int rcands = 0;                         // 当前右破（下坡）糖果数量
    int rbase = 0;                          // 当前右破坡顶糖果数量
    while(index != arr.size()){
        if(arr[index] > arr[index - 1]){    //// 当前处于上坡状态
            res += ++lbase;                 // 边上坡边结算上坡糖果数
            index ++;
        } else if(arr[index] < arr[index - 1]){     //// 当前处于下坡状态
            next = nextMinIndex1(arr, index - 1);   // 注意，这里是从index-1开始找
            rcands = rightCands(arr, index-1, next);// 结算下坡糖果
            rbase = next - (index-1) + 1;           // 下坡坡顶糖果数量
            // 按照上下坡梯度，结算当前总糖果数，并减去多余计算的坡峰
            res += rcands + (rbase > lbase ? -lbase : -rbase); 
            lbase = 1;
            next ++;                                // 从坡底的下一个继续上坡
            index = next;
        } else { // arr[i] == arr[i-1]
            res += 1;
            lbase = 1;
            index++;
        }
    }
    return res;
}
// 获取下一个上坡起始点
int nextMinIndex1(vector<int> arr, int start)
{
    for(int i = start; i < arr.size()-1; i ++)
        if(arr[i] <= arr[i+1])
            return i;
    return arr.size()-1;
}
// 结算当前右侧的糖果
int rightCands(vector<int> arr, int left, int right)
{
    int n = right - left + 1;
    return n * (n + 1) / 2;
}

/**
 * 分糖果问题：进阶问题
 */
int candy2(vector<int> arr);
int nextMinIndex2(vector<int> arr, int start);
vector<int> rightCandsandBase(vector<int> arr, int left, int end);

int candy2(vector<int> arr)
{
    if(arr.size() == 0)
        return 0;
    int index = nextMinIndex2(arr, 0);
    vector<int> rcb = rightCandsandBase(arr, 0, index++);
    int res = rcb[0];
    int lbase = 1;
    int next = 0;
    int same = 1;
    while(index != arr.size()){ // 这个index其实是从1开始的
        if(arr[index] > arr[index-1]){
            res += ++lbase;
            same = 1;
            index ++;
        }else if(arr[index] < arr[index-1]){
            next = nextMinIndex2(arr, index-1);
            rcb = rightCandsandBase(arr, index-1, next++);
            // rcb = {rcands, rbase}
            if(rcb[1] <= lbase){
                res += rcb[0] - rcb[1];
            }else{
                res += rcb[0] - rcb[1] - lbase*same + rcb[1]*same;
            }
            index = next;
            lbase = 1;
            same = 1;
        }else{
            res += lbase;
            same++;
            index++;
        }
    }
    return res;
}
int nextMinIndex2(vector<int> arr, int start)
{
    for(int i = start; i < arr.size()-1; i++)
        if(arr[i] < arr[i+1])
            return i;
    return arr.size() - 1;
}
vector<int> rightCandsandBase(vector<int> arr, int left, int right)
{
    int base = 1;
    int cands = 1;
    for(int i = right-1; i >= left; i--){
        base += arr[i]==arr[i+1] ? 0 : 1;
        cands += base;
    }
    return vector<int> {cands, base};
}

/**
 * generate n pairs blocks
 */
void searchNPairsBlocks(string str, int n, int rest)
{
    if(n < 0 || rest < 0)
        return;
    if(n == 0 && rest == 0)
       cout << str << endl;
    
    str.push_back('(');
    searchNPairsBlocks(str, n-1, rest+1);
    str.back() = ')';
    searchNPairsBlocks(str, n, rest-1);
}
void genNParisBlocks(int n)
{
    if(n <= 0)
        return;
    
    searchNPairsBlocks("", n, 0);
}

/**
 * strange priter
 */
int strangePrinter(string s) {
    if(s.size() <= 1) return s.size();

    vector<vector<int>> m(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); i++) m[i][i]=1;
    for(int step = 1; step < s.size(); step++)
    {
        for(int i = 0; i < s.size()-step; i++)
        {
            int j = i+step;
            m[i][j] = m[i+1][j] + 1;
            for(int k = i+1; k <= j; k++)
                if(s[i] == s[k])
                    m[i][j] = min(m[i][j], m[i+1][k-1]+m[k][j]);
        }
    }
    return m[0].back();
}

#include <windows.h>
int main()
{
    string s;
    while(cin >> s)
        cout << strangePrinter(s) << endl;
    return 0;
}

