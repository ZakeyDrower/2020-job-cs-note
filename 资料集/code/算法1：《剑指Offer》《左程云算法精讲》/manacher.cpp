#include<bits/stdc++.h>
using namespace std;

string manacherString(const string & s)
{
    string res = "#";
    for(char & c : s) {
        res += string(c) + "#";
    }
    return res;
}






string manacher(const string & str)
{
    if(str.size() < 2)
        return str;
    
    
}





int main()
{
    string s = "asdfgfdfghjkjhgfdlp";
    cout << manacher(s) << endl;
    return 0;
}