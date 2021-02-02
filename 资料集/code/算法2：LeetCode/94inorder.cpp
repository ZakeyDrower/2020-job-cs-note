#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

bool isLeaf(TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
}

vector<int> inorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};

    vector<int> res{};
    stack<TreeNode*> s;
    s.push(root);
    unordered_set<TreeNode*> visited;
    while(!s.empty()) {
        TreeNode* top = s.top();
        if(isLeaf(top)){
            res.push_back(top->val);
            s.pop();
        }else if(top->left == nullptr || visited.count(top)) {
            res.push_back(top->val);
            s.pop();
            if(top->right != nullptr) s.push(top->right);
        }else {
            visited.insert(top);
            s.push(top->left);
        }
    }
    return res;
}

int main()
{
    cout << "hello world" << endl;
}