#ifndef _NIUBI_HEADER_H
#define _NIUBI_HEADER_H
#include <bits/stdc++.h>
using namespace std;
#endif

#ifndef _DS_TREENODE
#define _DS_TREENODE
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};
#endif

#ifndef _DS_LISTNODE
#define _DS_LISTNODE
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int v) : val(v), next(nullptr) {};
};
#endif