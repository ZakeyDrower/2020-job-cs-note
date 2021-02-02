#include <bits/stdc++.h>
using namespace std;

class npy{
private:  
    string name;
    int age;
    static int npy_num;

public:  
    npy(string s, int a){
        if(npy_num > 3)
            cout << " Too many girlfriends! " << endl;
        else{
            name = s;
            age = a;
            npy_num++;
        }
    };
    string getName(){ return this->name;}
    int getAge(){ return this->age; }
};

int rec1(int n, unordered_map<int, int> & memo)
{
    if(n < 1)
        return 0;
    if(memo.find(n) != memo.end())
        return memo[n];
    int res = 1;
    for(int i = 1; i < 7; i++){
        res += rec1(n-i, memo);
    }
    memo[n] = res;
    return memo[n];
}

int rec2(int n)
{
    if(n < 1)
        return 0;
    int res = 1;
    for(int i = 1; i < 7; i++)
        res += rec2(n-i);
    return res;
}

int main()
{
    // unordered_map<int, int> memo;
    // cout << rec1(10, memo);
    // int is[8];
    // cout << sizeof(is) << endl;
    // vector<bool> bs(8,0);
    // bitset<65> bbs;
    // cout << sizeof(bs) << ' ';
    // for(auto p = bs.begin(); p != bs.end(); ++p) cout << *p; cout << endl;
    // cout << sizeof(bbs) << ' ' << bbs.size() << ' '<< bbs;
    string s1 = "aaa";
    string s2 = "bbb";
    cout << s1 << '\t' << s2 << endl;
    s2 = std::move(s1);
    cout << s1 << '\t' << s2 << endl;
    return 0;
}