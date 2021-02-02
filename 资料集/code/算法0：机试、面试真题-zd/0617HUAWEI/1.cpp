#include<bits/stdc++.h>
using namespace std;

void processEqu(const string & equ, vector<char> & oper, vector<vector<int>> & atom)
{
    int numbuf = 0, i = 0;
    bool hasnum = false;
    vector<int> atombuf;
    while(i < equ.size()) {
        if( (equ[i] == '[')){
            if(hasnum) {
                atombuf.push_back(numbuf);
                atom.push_back(atombuf);
                oper.push_back('*');
                numbuf = 0;
                hasnum = false;
                atombuf = vector<int>();
            }
            if(i>0 && equ[i-1] == ']'){
                oper.push_back('*');
            }
        } else if(equ[i] == ']') {
            if(hasnum) {
                atombuf.push_back(numbuf);
                atom.push_back(atombuf);
                atombuf = vector<int>();
                hasnum = false;
                numbuf = 0;
            }
        } else if(equ[i] == ',') {
            if(equ[i+1] == '[' || equ[i-1]==']' ) {
                oper.push_back('+');
                if(hasnum) {
                    atombuf.push_back(numbuf);
                    atom.push_back(atombuf);
                    numbuf = 0;
                    hasnum = false;
                    atombuf = vector<int>();
                }
            } else {
                atombuf.push_back(numbuf);
                numbuf = 0;
                hasnum = false;
            }
        } else {
            numbuf = hasnum ? (numbuf*10+equ[i]-'0') : (equ[i]-'0');
            hasnum = true;
        }
        i++;
    }
}

int main()
{
    string equ = "[1,2][2,3],[3[4,5]]";
    vector<char> type;
    vector<vector<int>> atom;
    processEqu(equ, type, atom);
    cout << "processed" << endl;
}