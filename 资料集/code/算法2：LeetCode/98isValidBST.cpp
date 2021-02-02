#include "header.h"

struct RetType {
    long long min;
    long long max;
    bool isBST;
    RetType(): min(numeric_limits<long long>::max()), max(numeric_limits<long long>::min()), isBST(true) {};
    RetType(TreeNode* node) :
        min(node->val), max(node->val), isBST(true) {};
};

RetType dp(TreeNode* node) {
    if(node == nullptr){
        return RetType();
    }

    RetType cur(node);
    if(node->left == nullptr && node->right == nullptr){
        return cur;
    }

    RetType left = dp(node->left);
    RetType right= dp(node->right);
    cur.isBST = cur.min > left.max && cur.max < right.min && left.isBST && right.isBST;

    cur.min = left.min == numeric_limits<long long>::max() ? cur.min : std::min(cur.min, left.min);
    cur.max = right.max == numeric_limits<long long>::min() ? cur.max : std::max(cur.max, right.max);
    return cur;
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    RetType res = dp(root);
    return res.isBST;
}

int main()
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(-1);
    cout << isValidBST(root);
}