#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int id;
    int weight;
    bool caled; 
    vector<Node*> subs;
    Node(int i) : id(i), weight(1), caled(false), subs({}) {}; 
    Node* getMaxWeightNode();
    //int delMaxWeightNode();
};

Node* Node::getMaxWeightNode() {
    if(subs.size() == 0)
        return nullptr;
    int max = 0;
    Node* ret = nullptr;
    for(Node* n : subs){
        if(n->weight > max){
            max = n->weight;
            ret = n;
        }
    }
    return ret;
}

// int Node::delMaxWeightNode() {
//     Node* mn = getMaxWeightNode();
//     if(mn == nullptr)
//         return 0;
//     else {
//         return this->weight - mn->weight;
//     }
// }

int calWeight(Node* node)
{
    node->caled = true;
    if(node->subs.size()==0){
        return 1;
    }
    for(Node* n : node->subs) {
        int tmp = n->caled ? 0 : calWeight(n);
        node->weight += tmp;
    }
    return node->weight;
}

int main()
{
    int n, p;
    map<int, Node*> in; // id to node
    cin >> n >> p;
    int pre, next;
    while(p--) {
        cin >> pre >> next;
        if(in.find(pre) == in.end()){
            Node* node = new Node(pre);
            in[pre] = node;
        }
        if(in.find(next) == in.end()){
            Node* node = new Node(next);
            in[next] = node;
        }
        in[pre]->subs.push_back(in[next]);            
    }

    for(auto it = in.begin(); it != in.end(); ++ it) {
        if(it->second->caled == false){
            calWeight(it->second);
        }
    }

    // 广搜
    queue<Node*> q;
    q.push(in[1]);
    int cnt = 1;
    while(!q.empty()) {
        int tmp;
    }
}