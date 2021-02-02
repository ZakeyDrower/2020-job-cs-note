#include<bits/stdc++.h>
using namespace std;

bool isValid(const vector<int> & cur, int line) {
    for(int i = 0; i < line; i++) {
        if(abs(cur[i] - cur[line]) == line - i)
            return false;
    }
    return true;
}

vector<string> genRes(const vector<int> & cur) {
    vector<string> sol;
    string s;
    for(int i = 0; i < cur.size(); i ++) {
        s = "";
        for(int j = 0; j < cur.size(); j++) {
            s += cur[i]==j ? "Q" : ".";
        }
        sol.push_back(s);
    }
    return sol;
}

void search(int line, vector<int> & visited, vector<int> & cur, vector<vector<string>> & res) {
    if(line == visited.size()){
        res.push_back(genRes(cur));
    }

    for(int i = 0; i < visited.size(); i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            cur[line] = i;
            if(isValid(cur, line))
                search(line+1, visited, cur, res);
            visited[i] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    if(n == 0) return {{}};
    vector<vector<string>> res;
    vector<int> cur(n, 0);
    vector<int> visited(n, 0);
    search(0, visited, cur, res);
    return res;
}

int main()
{
    // vector<int> t{1,0,3,2};
    // // vector<string> res = genRes(t);
    // cout << isValid(t,3);

    for(auto ss : solveNQueens(4)) {
        for(auto s : ss)
            cout << s << endl;
        cout << endl;
    }
}