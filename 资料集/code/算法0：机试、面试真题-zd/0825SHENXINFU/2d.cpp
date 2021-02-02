#include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* pre;
    Node* next;
    Node(char a) : val(a), pre(nullptr), next(nullptr) {};
};

int main()
{
    string s;
    int n;
    cin >> s >> n;
    unordered_map<char, Node*> map;
    while(n--) {
        char a, b;
        cin >> a >> b;
        if(map.find(a) == map.end()) {
            Node* node = new Node(a);
            map[a] = node;
        }
        if(map.find(b) == map.end()) {
            Node* node = new Node(b);
            map[b] = node;
        }
        map[a]->next = map[b];
        map[b]->pre = map[a];
    }
    for(char c = '0'; c <= '9'; ++c) {
        if(map.find(c) != map.end()) {
            Node* cur = map[c];
            Node* ori = cur, tail = cur->next;
            while(tail != nullptr && tail->next != nullptr) {
                tail = tail->next;
            }
            while(ori->pre != nullptr) {
                ori->next = tail;
                ori = ori->left
            }
        }
    }
    for(char & c : s) {
        if(map.find(c) == map.end())
            continue;
        else {
            Node* node = map[c];
            c = node->next->val;
        }
    }
    cout << s << endl;
    return 0;
}
