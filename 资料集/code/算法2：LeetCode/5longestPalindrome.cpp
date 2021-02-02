#include <bits/stdc++.h>
using namespace std;

string manacherString(string str)
{
    string s(str.size()*2+1, '#');
    int index = 0;
    for(int i = 1; i < s.size(); ++ i) {
        if(i & 1){
            s[i] = str[index++];
        }
    }
    return s;
}

string longestPalindrome(string str)
{
    if(str == "") return "";

    string && s = manacherString(str);
    vector<int> parr(s.size(), 1);
    int index = -1;
    int pr = -1;
    // int max_index = 0;
    // int max_r = 1;
    for(int i = 0; i < s.size(); ++ i) { // 从1开始
        parr[i] = pr > i ? min(parr[2*index - i], pr-i) : 1; // jiasu
        // 扩充：当前右边界不达到字符串最右，且不达到最左（不越界）
        while(i + parr[i] < s.size() && i - parr[i] >= 0) {
            if(s[i+parr[i]] == s[i-parr[i]])
                parr[i] ++;
            else
                break;
        }
        if(i + parr[i] > pr) {
            pr = i + parr[i];
            index = i;
        }
        // if(parr[i] > max_r) {
        //     max_index = i;
        //     max_r = parr[i];
        // }
    }

    // 一共有多少个回文子串
    int cnt = 0; // counter
    for(int & r: parr) {
        if(r > 2)
            cnt += (r-1)/2;
    }
    return cnt;

    // 求最长回文子串
    

    
    // // cout << "length : " << max_r - 1 << endl;
    // // string res(s.begin() + max_index - max_r + 1, s.begin() + max_index + max_r);
    // // cout << "res : " << res << endl;
    // // for(int i = res.size()-1; i >= 0 ; -- i) {
    // //     if(res[i] == '#')
    // //         res.erase(res.begin() + i);
    // // }
    // // cout << "processed : " << res << endl;
    // string res;
    // if(max_index & 1) {
    //     res = string(str.begin() + (max_index+1)/2-1 - max_r/2 + 1, str.begin() + (max_index+1)/2-1 + max_r/2);
    // } else {
    //     res = string(str.begin() + max_index/2 - max_r/2, str.begin() + max_index/2 + max_r/2);
    // }
    // //cout << "size : " << res.size() << endl;
    // return res;
}

int main()
{
    string s = "abbcbb";
    cout << longestPalindrome(s) << endl;
    return 0;
}