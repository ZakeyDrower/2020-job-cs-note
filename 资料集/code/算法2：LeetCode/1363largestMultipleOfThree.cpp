#include <bits/stdc++.h>
using namespace std;

string largestMultipleOfThree(vector<int> & digits) 
{
    sort(digits.begin(), digits.end(), [](int a, int b){return a > b;});
    // int bin = pow(2, digits.size());    // eg: digits{5,4,2,1}, bin = 2^4 = 16
    // int reslen = 0;
    if(digits[0] == 0) return "0";
    string res = "";
    vector<int> r1, r2;
    for(int i : digits) {
        res += to_string(i);
        if(i%3 == 1) r1.push_back(i);
        if(i%3 == 2) r2.push_back(i);
    }

    int dif = (r1.size()-r2.size()) * (r1.size() > r2.size() ? 1 : -1);
    if(dif % 3 == 1) {
        char rm = r1.size()>r2.size() ? r1.back()+'0' : r2.back()+'0';
        res.erase(res.begin() + res.find_last_of(rm));
    }else if(dif % 3 == 2) {
        if(min(r1.size(), r2.size()) > 0){
            char rm = r1.size()>r2.size() ? r2.back()+'0' : r1.back()+'0';
            res.erase(res.begin() + res.find_last_of(rm));
        }else{ // min == 0
            char rm1 = r1.size()>r2.size() ? r1.back()+'0' : r2.back()+'0';
            res.erase(res.begin() + res.find_last_of(rm1));
            char rm2 = r1.size()>r2.size() ? r1[r1.size()-2]+'0' : r2[r2.size()-2]+'0';
            res.erase(res.begin() + res.find_last_of(rm2));
        }
    }

    return res;     
}

int main()
{
    vector<int> a{2,5};
    cout << largestMultipleOfThree(a) << endl;
}