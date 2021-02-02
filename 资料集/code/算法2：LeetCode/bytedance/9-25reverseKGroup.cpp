#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int i) : val(i), next(nullptr) {};
};

bool countK(Node* h, int k) {
    Node* p = h;
    while(k--) {
        if(p == nullptr) return false;
        else p = p->next;
    }
    return true;
}

Node* reverseKGroup(Node* head, int k) {
    if(!countK(head, k))
        return head;
    
    Node* cur = head, *n = head->next;
    int K = k;
    while(--K) {
        Node* tmp = n->next;
        n->next = cur;
        cur = n;
        n = tmp;  
    }
    head->next = reverseKGroup(n, k);
    return cur;
}

int main() {
    reversekGroup();
}