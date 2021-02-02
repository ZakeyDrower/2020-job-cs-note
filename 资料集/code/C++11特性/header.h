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

// about typedef
typedef int int_x;
typedef struct { char c;} struct_s;
typedef int* p_int_p;
// higher level
typedef int int_A[];
typedef int int_f(); // 定义一个函数名为int_f，参数为空，返回值为int的  函数模板
typedef int int_g(int);  // 定义一个函数名为int_g，含一个int参数，返回值为int的  函数模板


// 移动语义实现高效swap
template<typename T>
void swap(T& a, T& b)
{
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}