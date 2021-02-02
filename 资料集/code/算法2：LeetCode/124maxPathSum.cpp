#include "header.h"

int sh(TreeNode *  node, int & res)
{
    if(node == nullptr) return 0;

    int l = sh(node->left, res), r = sh(node->right, res);
    int cutoff = node->val + max(0, l) + max(0, r);
    int single = node->val + max(0, max(l, r));
    res = max(res, max(cutoff, single));
    return single;
}

int maxPathSum(TreeNode * root)
{
    int res = numeric_limits<int>::min();
    sh(root, res);
    return res;
}

int main()
{
    TreeNode * root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(-1);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    //root = new TreeNode(-1);
    cout <<  maxPathSum(root);
    return 0;
}