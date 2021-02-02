#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v) : val(v) , next(nullptr) {};
    ~Node() {delete next;};
};

void printList(Node* p){
    if(p == nullptr)
        cout << endl;
    else {
        cout << p->val << ' ';
        printList(p->next);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    Node* ph = new Node(0); // pre head
    Node* p = ph;
    int nn = n;
    while(nn--) {
        int v;
        cin >> v;
        p->next = new Node(v);
        p = p->next;
    }

    if(k > n){
        printList(ph->next);
        return 0;
    }
    
    p = ph;
    while(--k){
        p = p->next;
    }
    Node* del = p->next;
    p->next = del->next;
    del->next = nullptr;
    del->~Node();
    printList(ph->next);

    return 0;

}