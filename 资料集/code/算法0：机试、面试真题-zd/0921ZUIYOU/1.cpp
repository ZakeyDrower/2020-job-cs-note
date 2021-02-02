#include<bits/stdc++.h>
using namespace std;

struct Node {
    char i;
    // short val;
    Node* next;
    Node(int i) : val(i), next(nullptr) {};
};

bool isValid(){
    return true;
}


Node* listSum(Node* a, Node* b)
{
    Node* pre = new Node(0);
    Node* p = pre;
    int carry = 0;
    while(a != nullptr && b != nullptr) {
        int curval = (a->val + b->val) + carry;
        p->next = new Node(curval % 10);
        carry = curval / 10;
        p = p->next;
        a = a->next;
        b = b->next;
    }
    while(a != nullptr) {
        int curval = a->val + carry;
        p = new Node(curval % 10);
        carry = curval / 10;
        p = p->next;
        a = a->next;
    }
    while(b != nullptr) {
        int curval = b->val + carry;
        p = new Node(curval % 10);
        carry = curval / 10;
        p = p->next;
        b = b->next;
    }
    if(carry)
        p->next = new Node(carry);

    return pre->next;
}

int main ()
{
    Node* n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);

    Node* n2 = new Node(4);
    n2->next = new Node(8);
    n2->next->next = new Node(9);

    Node* res = listSum(n1, n2);
    while(res != nullptr){
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;
    return 0;
}