#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool endRec(ListNode* head, int k){
    while(k--){
        if(head==nullptr)   return true;
        else head = head->next;
    }
    return false;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(endRec(head, k)) return head;

    ListNode* cur = head, *n = head->next, *tmp = n->next;
    int K = k;
    while(--k){
        tmp = n->next;
        n->next = cur;
        cur = n;
        n = tmp;
    }
    head->next = reverseKGroup(n, K);
    return cur;
}


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* newhead = reverseKGroup(head, 1);
    while(newhead != nullptr){
        cout << newhead->val << "->";
        newhead = newhead->next;
    }
}