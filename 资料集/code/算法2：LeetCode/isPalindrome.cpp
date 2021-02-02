#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    int s = to_string(n);
    string rs = string(s.rbegin(), s.rend());
    return s == rs;
}

int main()
{
    vector<int> ls{1,11,121,132,234432,5789};
    for(int i : ls) {
        cout << isPalindrome(i) << endl;
    }
    return 0;
}