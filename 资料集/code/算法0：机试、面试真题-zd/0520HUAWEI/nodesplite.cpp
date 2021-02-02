#include<bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    string name;
    Node(int id, string name) : id(id), name(name) {};
};

int main()
{
    string sname;
    cin >> sname;
    vector<Node> vec;
    string line;
    while(cin >> line){
        int id = atoi(string(line.begin(), line.begin() + line.find(',')).c_str());
        string name = string(line.begin() + line.find(',') + 1, line.end());
        vec.push_back(Node(id, name));
    }
    
    return 0;
}
/*
*
1,name1
2,name2
3,*
4,name4
5,name5
*/