// 作者：我要好好刷题
// 链接：https://www.nowcoder.com/discuss/422885
// 来源：牛客网

// 第一题：给一个顺序链表，可能有重复的数字，然后输入一个新的链表，使得列表中每个数字都重复了3次。

// 第二题：给了N个请求，由两部分组成[a,b]，a为占用内存，b为满足这个请求的收益；然后有M个服务器，每个服务器内存为c，如果c>=a，那就是能满足该请求，问M个服务器所能获得的最大的增益（每台服务器只能满足一个请求）。

// 第三题：给一个二叉树，然后计算树的最大路径；二叉树举例：1(2,3(4,5)) ： 1是根，2和3是叶子，然后3又有4，5叶子。

#include <bits/stdc++.h>
using namespace std;

/**
 * Problem 1
 */

/**
 * Problem 2
 */
struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

TreeNode * deSerializeTree(string & s, int & l)
{
    if(l >= s.size())
        return nullptr;
    
    TreeNode * node;
    int r = l;
    int val;

    while(s[r] == '-' || (s[r]<='9' && s[r] >= '0'))
        r++;
    val = stoi(string(s.begin()+l, s.begin()+r));
    node = new TreeNode(val);
    
    l = r;
    while(l < s.size() && !(s[l] == '-' || (s[l]<='9' && s[l] >= '0')))
        l++;
    if(l == s.size() || (s[l-1] == ',' && s[l-2] != '('))
        return node;

    if(s[l-2] != '(')
        node->left = deSerializeTree(s, l);
    node->right = deSerializeTree(s, l);
    return node;    
}

void recMTP(TreeNode * node, int sum, int & res)
{
    if(node == nullptr)
        return;
    
    sum += node->val;
    if(node->left == nullptr && node->right == nullptr){
        res = max(res, sum);
    }else{
        recMTP(node->left, sum, res);
        recMTP(node->right, sum, res);
    }    
}

int getMaxTreePath(string tree)
{
    int ind = 0;
    TreeNode * root = deSerializeTree(tree, ind);
    int res = numeric_limits<int>::min();
    recMTP(root, 0, res);
    return res;
}

/**
 * 二叉树最大路径和（任意节点到任意节点）
 */
int maxrec(TreeNode * p, int & res)
{
    if(p == nullptr) return 0;
    
    int l = maxrec(p->left, res), r = maxrec(p->right, res);
    int ret = p->val + max(0, max(l, r));
    int cutoff = p->val + max(0, l) + max(0, r);

    res = max(res, max(ret, cutoff));

    return ret;
}

int maxPathSum(TreeNode *root)
{
    if(root == 0)
        return 0;

    int res = numeric_limits<int>::min();
    maxrec(root, res);
    return res;
}

int main()
{
    string str = "-1(3,2(0,-1(1,3)))";
    cout << getMaxTreePath(str);
    return 0;
}