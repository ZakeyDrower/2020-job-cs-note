#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int i) : val(i), left(nullptr), right(nullptr) {};
};

void getPreorder(Node* & p, vector<int> & order)
{

    if(p == nullptr)
        return;
    getPreorder(p->left, order);
    order.push_back(p->val);
    // if(p->val < order.back())
    //     g_res = false;
    getPreorder(p->right, order);
    // 
}

bool judgePreorder(vector<int> & order)
{
    for(int i = 0; i < order.size()-1; ++ i){
        if(order[i] > order[i+1])
            return false;
    }
    return true;
}

// 思路1：使用前序遍历检查
bool judge1(Node* root)
{
    if(root == nullptr)
        return true;
    vector<int> preorder;
    getPreorder(root, preorder);
    return judgePreorder(preorder); // g_res;
}


int main()
{

}