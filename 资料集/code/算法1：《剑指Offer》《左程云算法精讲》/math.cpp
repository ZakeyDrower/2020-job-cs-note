#include <bits/stdc++.h>
using namespace std;

bool equal(double d1, double d2)
{
    return abs(d1 - d2) < 0.00000001 ? true : false;
}

double Power(double base, int exponent)
{
    if (exponent == 0)
        return 1;
    if (equal(base, 0))
        return 0;
    double res = 1;
    for (unsigned int i = 0; i < (unsigned int)(abs(exponent)); i++)
    {
        res *= base;
    }
    return exponent > 0 ? res : 1 / res;
}

vector<string> Permutation(string str)
{
    vector<string> vec;
    sort(str.begin(), str.end());
    do
    {
        vec.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
    return vec;
}

string regularization(string str)
{
    if (str == "")
        return "";
    string res = "";
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length();)
    {
        res.push_back(str[i]);
        int count = 1;
        while (i < str.length() && str[++i] == res.back())
        {
            count++;
        }
        res += to_string(count);
    }
    return res;
}

void myPerRec(vector<string> &vec, string str, int n)
{
    if (n == str.size())
    {
        vec.push_back(str);
        return;
    }

    for (int i = n; i < str.size(); i++)
    {
        swap(str[i], str[n]);
        myPerRec(vec, str, n + 1);
        swap(str[i], str[n]);
    }
}
vector<string> myPermutation(string str)
{
    sort(str.begin(), str.end());
    vector<string> vec;
    myPerRec(vec, str, 0);
    return vec;
}

int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.size() == 0)
        return 0;
    map<int, int> map;
    int max_count = numbers.size() / 2;
    for (int i : numbers)
    {
        if (map.find(i) != map.end())
            map[i] = map[i] + 1;
        else
            map[i] = 1;
        if (map[i] > max_count)
        {
            max_count = map[i];
            return i;
        }
    }

    return 0;
}

int maxSubArrSum(vector<int> arr)
{
    if (arr.size() == 0)
        return 0;
    int sum = 0;
    int max_sum = 0x80000000;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];

        if (sum > max_sum)
            max_sum = sum;
    }
    return max_sum;
}

// doesn't work. need a RECORDER
int maxSubArrSum_recursion(vector<int> arr, int r)
{
    if (r == 0)
        return arr[r];
    int pre = maxSubArrSum_recursion(arr, r - 1);
    if (pre < 0)
        return arr[r];
    else
        return pre + arr[r];
}

int NumberOf1Between1AndN_Solution_nlogn(int n)
{
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        string str = to_string(i);
        count += std::count(str.begin(), str.end(), '1');
    }
    return count;
}

int countSolution(int num)
{
    if (num <= 0)
        return 0;
    int len = (to_string(num)).size();
    if (len == 1)
        return 1;
    int count = 0, high = num / pow(10, len - 1);
    if (high == 1)
        count += num % int(pow(10, len - 1)) + 1;
    else
        count += int(pow(10, len - 1));
    count += high * (len - 1) * pow(10, len - 2);
    count += countSolution(int(num % int(pow(10, len - 1))));
    return count;
}

int NumberOf1Between1AndN_Solution(int n)
{
    int count = countSolution(n);
    return count;
}

bool isUgly(int a)
{
    while (a % 2 == 0)
        a /= 2;
    while (a % 3 == 0)
        a /= 3;
    while (a % 5 == 0)
        a /= 5;
    return (a == 1) ? true : false;
}

int GetUglyNumber_Solution_On2(int index)
{
    if (index <= 0)
        return 0;

    int con = 0, i = 0;
    while (con < index)
    {
        i++;
        if (isUgly(i))
            con++;
    }
    return i;
}

int GetUglyNumber_Solution(int index)
{
    vector<int> v{1};
    int a = 0, b = 0, c = 0;
    while (--index)
    {
        while (v[a] * 2 <= v.back())
            a++;
        while (v[b] * 3 <= v.back())
            b++;
        while (v[c] * 5 <= v.back())
            c++;
        v.push_back(min(min(v[a] * 2, v[b] * 3), v[c] * 5));
    }
    return v.back();
}

int FirstNotRepeatingChar(string str)
{
    if (str == "")
        return -1;
    int res = 100000;
    unordered_map<char, int> map;
    for (char c : str)
        map[c] += 1;
    for (auto p = map.begin(); p != map.end(); p++)
    {
        if (p->second == 1)
            res = min(res, int(str.find(p->first)));
    }
    return res == 100000 ? -1 : res;
}

int findFlag(int t)
{
    int i = 1;
    while ((t & i) != i)
    {
        i <<= 1;
    }
    return i;
}

void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
    int t = 0;
    for (int i : data)
        t ^= i;
    int flag = findFlag(t);
    *num1 = *num2 = 0;
    for (int i : data)
    {
        if ((flag & i) == flag)
        {
            *num1 ^= i;
        }
        else
        {
            *num2 ^= i;
        }
    }
}

// 约瑟夫环问题：递归解法
int LastRemaining_Solution_rec(int n, int m)
{
    if (n == 0)
        return -1;
    return (n == 1) ? 0 : (LastRemaining_Solution_rec(n - 1, m) + m) % n;
}
int LastRemaining_Solution(int n, int m)
{
    if (n == 0)
        return -1;
    int a = 0, b = 0;
    for (int i = 2; i <= n; i++)
    {
        b = (a + m) % i;
        a = b;
    }
    return a;
}

//巧妙求和1-n
class SumClass
{
private:
    static int N;
    static int SUM;

public:
    SumClass()
    {
        N++;
        SUM += N;
    }
    static void Reset() { N = 0, SUM = 0; }
    static int GetSum() { return SUM; }
};

int SumClass::N = 0;
int SumClass::SUM = 0;

int Sum_Solution(int n)
{
    SumClass::Reset();
    SumClass *p = new SumClass[n];
    delete[] p;
    return SumClass::GetSum();
}

// 二进制求加法
int Add(int num1, int num2)
{
    int sum = num1;
    while (num2 != 0)
    {
        sum = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = sum;
    }
    return sum;
}

// 剪绳子
int cutRope(int number)
{
    if (number < 2 || number > 60)
        return 0;
    if (number == 2)
        return 1;

    int res = 1;
    int m = round(sqrt(number));
    for (int i = 0; i < m - 1; i++)
    {
        res *= m;
        number -= m;
    }
    if (number != 0)
        res *= number;
    return res;
}

int makeWeiSum(int a, int b)
{
    string s = to_string(a) + to_string(b);
    int sum = 0;
    for (char c : s)
    {
        sum += c - '0';
    }
    return sum;
}

void search(int t, int i, int j, int r, int c, int &count, vector<vector<bool>> &vec)
{
    if (i < 0 || j < 0 || i == r || j == c || vec[i][j] == true)
        return;

    if (makeWeiSum(i, j) <= t)
    {
        count++;
        vec[i][j] = true;
        search(t, i + 1, j, r, c, count, vec);
        search(t, i, j + 1, r, c, count, vec);
        search(t, i - 1, j, r, c, count, vec);
        search(t, i, j - 1, r, c, count, vec);
    }
}

int movingCount(int threshold, int rows, int cols)
{
    if (rows <= 0 || cols <= 0 || threshold == 0)
        return 0;
    int count = 0;
    vector<vector<bool>> vec(rows, vector<bool>(cols, false));
    search(threshold, 0, 0, rows, cols, count, vec);
    return count;
}

bool searchpath(int i, int j, bool *rec, char *mat, int r, int c, char *s)
{
    if (i < 0 || j < 0 || i >= r || j >= c || rec[i * c + j] == true)
        return false;

    bool res = false;
    if (mat[i * c + j] == *s)
    {
        rec[i * c + j] = true;
        if (*(s + 1) == '\0')
            return true;
        res = searchpath(i + 1, j, rec, mat, r, c, s + 1) ||
              searchpath(i - 1, j, rec, mat, r, c, s + 1) ||
              searchpath(i, j + 1, rec, mat, r, c, s + 1) ||
              searchpath(i, j - 1, rec, mat, r, c, s + 1);
        if (res == false)
            rec[i * c + j] = false;
    }

    return res;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
    if (str == nullptr)
        return false;

    bool *rec = new bool[rows * cols];
    bool res = false;
    for (int i = 0; i < cols * rows; i++)
        rec[i] = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            res = res || searchpath(i, j, rec, matrix, rows, cols, str);
        }
    }
    return res;
}

bool isNumeric(char *s)
{
    if (s == nullptr || *s == '\0')
        return false;
    bool a = 0, b = 0, c = 0;
    if (*s == '+' || *s == '-') // +/-
        s++;
    if (*s == '\0')
        return false;
    while (*s != '\0' && *s >= '0' && *s <= '9')
    { // a
        a = 1;
        s++;
    }
    if (*s == '\0')
    {
        if (a == 1)
            return true;
        return false;
    }

    if (*s == '.')
    { // .
        //if(a == 0) return false;
        s++;
        while (*s >= '0' && *s <= '9')
        { // b
            b = 1;
            s++;
        }
        if (b == 0)
            return false;
    }
    if (*s == '\0')
        return true;
    if (*s == 'e' || *s == 'E')
    {
        //if(a == 0) return false;
        s++;
        if (*s == '\0')
            return false;
        if (*s == '+' || *s == '-')
        {
            s++;
        }
        while (*s >= '0' && *s <= '9')
        {
            c = 1;
            s++;
        }
        if (c == 0)
            return false;
    }
    if (*s == '\0')
        return true;
    else
        return false;
}

bool isNumeric_reg(char *s)
{
    if (s == nullptr)
        return false;
    regex reg("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
    return regex_match(s, reg);
}

int main()
{

    char *p = new char[100];
    while (cin >> p)
        cout << isNumeric(p) << endl
             << isNumeric_reg(p) << endl;

    return 0;
}