#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
}TreeNode;

TreeNode * buildTree(const string & str, int & i){
    if(i == str.size()){
        return nullptr;
    }
    if(str[i] == '#'){
        i++;
        return nullptr;
    }

    TreeNode * node = new TreeNode(0);
    i++;
    node->left = buildTree(str, i);
    node->right = buildTree(str, i);
    return node;
}

bool isLeaf(TreeNode * node){
    return node->left == nullptr && node->right == nullptr;
}

int doit(TreeNode * node);
int notdo(TreeNode * node);

unordered_map<TreeNode*, int> dmap;
unordered_map<TreeNode*, int> ndmap;

int doit(TreeNode * node){
    if(node == nullptr)
        return 0;
    
    if(dmap.find(node) != dmap.end())
        return dmap[node];

    dmap[node] = 1 + notdo(node->left) + notdo(node->right);
    return dmap[node];
}

int notdo(TreeNode * node){
    if(node == nullptr || isLeaf(node))
        return 0;

    if(ndmap.find(node) != ndmap.end())
        return ndmap[node];

    if(node->left == nullptr) { ndmap[node] = doit(node->right); return ndmap[node];}
    if(node->right == nullptr) { ndmap[node] = doit(node->left); return ndmap[node];}

    if(isLeaf(node->left) && isLeaf(node->right)) { ndmap[node] = 2; return ndmap[node];}
    if(isLeaf(node->left)) { ndmap[node] = 1 + doit(node->right); return ndmap[node];}
    if(isLeaf(node->right)) { ndmap[node] = 1 + doit(node->left);  return ndmap[node];}

    ndmap[node] = min(
        doit(node->left) + notdo(node->right),
        notdo(node->left) + doit(node->right)
    );

    return ndmap[node];
}

int main(){
    string str;
    cin >> str;
    int index = 0;
    TreeNode* root = buildTree(str, index);
    int d = doit(root);
    int nd = notdo(root);
    cout << min(d, nd) << endl;
    return 0;
}