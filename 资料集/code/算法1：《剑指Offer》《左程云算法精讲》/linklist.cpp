#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// create LinkList use vector
ListNode *CreateList(vector<int> vals)
{
    ListNode *p = new ListNode(0);
    ListNode *prehead = p;
    for (int val : vals)
    {
        p->next = new ListNode(val);
        p = p->next;
    }
    return prehead->next;
}

// find -k th
ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (pListHead == nullptr)
        return nullptr;
    ListNode *p1 = pListHead;
    ListNode *p2 = pListHead;
    while (--k)
    {
        p1 = p1->next;
        if (p1 == nullptr)
            return nullptr;
    }
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

// complex listNode clone
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr){};
};

RandomListNode *CreateRandomList(vector<int> vals)
{
    RandomListNode *p = new RandomListNode(0);
    RandomListNode *prehead = p;
    for (int val : vals)
    {
        p->next = new RandomListNode(val);
        p = p->next;
    }
    return prehead->next;
}

// time: O(n), space: O(n) for hashmap
RandomListNode *CloneWithMap(RandomListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    map<RandomListNode *, RandomListNode *> map;
    RandomListNode *head = new RandomListNode(pHead->label);
    RandomListNode *p = pHead, *cp = head;
    while (p != nullptr)
    {
        map[p] = cp;
        if (p->next != nullptr)
            cp->next = new RandomListNode(p->next->label);
        p = p->next;
        cp = cp->next;
    }
    cp = head, p = pHead;
    while (cp != nullptr)
    {
        cp->random = map[p->random];
        cp = cp->next, p = p->next;
    }
    return head;
}

// time: O(n), space: O(1)
RandomListNode *Clone(RandomListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    RandomListNode *p = pHead;
    while (p != nullptr)
    {
        RandomListNode *cp = new RandomListNode(p->label);
        cp->next = p->next;
        p->next = cp;
        p = cp->next;
    }
    p = pHead;
    while (p != nullptr)
    {
        if (p->random != nullptr)
            p->next->random = p->random->next;
        p = p->next->next;
    }
    p = pHead;
    RandomListNode *res = p->next;
    while (p != nullptr)
    {
        RandomListNode *pClone = p->next;
        p->next = pClone->next;
        p = p->next;
        if (p != nullptr)
            pClone->next = p->next;
    }
    return res;
}

// 如果有环，返回入环节点，否则返回空
ListNode *findCircle(ListNode *node)
{
    if (node == nullptr)
        return nullptr;
    ListNode *p = node;
    unordered_map<ListNode *, int> map;
    while (p != nullptr)
    {
        if (map[p] == 1)
            return p;
        map[p] = 1;
        p = p->next;
    }
    return nullptr;
}

ListNode *FindFirstCommonNode_s1(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    // 判断是否有环
    ListNode *tail1 = findCircle(pHead1);
    ListNode *tail2 = findCircle(pHead2);
    ListNode *p1 = pHead1, *p2 = pHead2;
    // 如果都无环
    if (tail1 == nullptr && tail2 == nullptr)
    {
        // 方法1 ： 使用栈
        stack<ListNode *> s1, s2;
        while (p1 != nullptr)
        {
            s1.push(p1);
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            s2.push(p2);
            p2 = p2->next;
        }
        ListNode *res = nullptr;
        while (s1.top() == s2.top())
        {
            res = s1.top();
            s1.pop();
            s2.pop();
            if (s1.empty() || s2.empty())
                break;
        }
        return res;
        // 方法2：简单
        while (p1 != p2)
        {
            p1 = p1 == nullptr ? pHead2 : p1->next;
            p2 = p2 == nullptr ? pHead1 : p2->next;
        }
        return p1;
    }
    // 如果有环，必为相同环，入环节点相等时
    if ((tail1 != nullptr) && (tail2 != nullptr) && (tail1 == tail2))
        while (p1 != p2)
        {
            p1 = (p1 == tail1->next) ? pHead2 : p1->next;
            p2 = (p2 == tail2->next) ? pHead1 : p2->next;
        }
    return p1;
    // 入环节点不同时
    if ((tail1 != nullptr) && (tail2 != nullptr) && (tail1 != tail2))
    {
        int c1 = 0, c2 = 0;
        ListNode *ct1 = tail1, *ct2 = tail2;
        while (ct1 != tail2)
        {
            ct1 = ct1->next;
            c1++;
        }
        while (ct2 != tail1)
        {
            ct2 = ct2->next;
            c2++;
        }
        return (ct1 < ct2) ? tail2 : tail1;
    }

    return nullptr;
}

// 相当于将“两个”链表串成一串（A = AB, B = BA),在寻找公共节点
// 还有个通用的方法，求出两个入环节点的长度
ListNode *FindFirstCommonNode_s2(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    ListNode *p1 = pHead1, *p2 = pHead2;
    while (p1 != p2)
    {
        p1 = (p1 == nullptr) ? pHead2 : p1->next;
        p2 = (p2 == nullptr) ? pHead1 : p2->next;
    }
    return p1;
}

ListNode *deleteDuplication(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *h, *p, *cp = pHead, *np = pHead;
    p = new ListNode(INT_MIN);
    h = p;
    int step;
    while (np != nullptr && cp != nullptr)
    {
        step = 0;
        while (np->val == cp->val)
        {
            step++;
            np = np->next;
            if (np == nullptr)
                break;
        }
        if (step == 1)
        {
            p->next = cp;
            p = p->next;
        }
        cp = np;
    }
    if (step == 1)
        p->next = cp;
    else
        p->next = nullptr;
    return h->next;
}

int main()
{
    ListNode *p1 = CreateList(vector<int>{1, 1, 2, 2, 3, 3, 4, 5});
    // ListNode *p2 = CreateList(vector<int>{0,9,8});
    // p2->next->next->next = p1->next->next->next->next;
    ListNode *p2 = deleteDuplication(p1);
    while (p2 != nullptr)
    {
        cout << p2->val << ' ';
        p2 = p2->next;
    }

    return 0;
}
