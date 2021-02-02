#include<bits/stdc++.h>
using namespace std;

class Node {
    int val;
    Node* next;
    Node(int i) : val(i), next(nullptr) {};
};

Node* recRev(Node* pre, Node* node, Node* next) {
    if(next == nullptr){
        node->next = pre;
        return node;
    }
    node->next = pre;
    return recRev(node, next, next->next);
}

int main()
{

}