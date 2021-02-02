#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

bool isLeaf(TreeNode *node)
{
    if (node == nullptr)
        return false;
    return node->left == nullptr && node->right == nullptr;
}

// print binary tree
void printTree(TreeNode *node, string pre = "")
{
    if (node == nullptr)
        return;
    cout << pre << node->val << endl;
    printTree(node->left, pre + "----");
    printTree(node->right, pre + "++++");
}

// print vector
void pvec(vector<int> v)
{
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}

// reconst use preOrder and VinOrder
TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() == 0)
        return nullptr;
    TreeNode *head = new TreeNode(pre[0]);
    if (pre.size() == 1)
    {
        head->left = nullptr;
        head->right = nullptr;
    }
    else
    {
        auto x = find(vin.begin(), vin.end(), pre[0]);
        int xa = x - vin.begin();
        head->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + xa + 1), vector<int>(vin.begin(), x));
        head->right = reConstructBinaryTree(vector<int>(pre.begin() + xa + 1, pre.end()), vector<int>(x + 1, vin.end()));
    }
    return head;
}

// get preOrder vector
vector<int> getPreOrderVector(TreeNode *p)
{
    if (p == nullptr)
        return vector<int>{};
    vector<int> v{p->val};
    vector<int> l = getPreOrderVector(p->left);
    v.insert(v.end(), l.begin(), l.end());
    vector<int> r = getPreOrderVector(p->right);
    v.insert(v.end(), r.begin(), r.end());
    return v;
}

//get preOrder string
string getPreOrderString(TreeNode *p)
{
    if (p == nullptr)
        return "";
    string s = std::to_string(p->val) + "!";
    return s + getPreOrderString(p->left) + getPreOrderString(p->right);
}

// return if pRoot2 in pRoot1
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    string s1 = getPreOrderString(pRoot1);
    string s2 = getPreOrderString(pRoot2);
    if (s1.find(s2) != std::string::npos)
        return true;
    else
        return false;
}

// mirror tree
void Mirror(TreeNode *pRoot)
{
    if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr))
        return;
    TreeNode *p = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = p;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

// print tree by layer
vector<int> PrintFromTopToBottom(TreeNode *root)
{
    if (root == nullptr)
        return vector<int>{};
    vector<int> res{};
    queue<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *t = s.front();
        s.pop();
        res.push_back(t->val);
        if (t->left != nullptr)
            s.push(t->left);
        if (t->right != nullptr)
            s.push(t->right);
    }
    return res;
}

bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.size() == 0)
        return false;
    if (sequence.size() == 1)
        return true;
    int i = sequence.size() - 1;
    while (i >= 0)
    {
        if (sequence.at(i) < sequence.back())
            break;
        else
            i--;
    }
    int cut_point = i + 1;
    while (i >= 0)
    {
        if (sequence.at(i) > sequence.back())
            return false;
        else
            i--;
    }

    if (cut_point == 0)
        return VerifySquenceOfBST(vector<int>(sequence.begin() + cut_point, sequence.end() - 1));
    if (cut_point == sequence.size() - 1)
        return VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + cut_point));
    return VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + cut_point)) && VerifySquenceOfBST(vector<int>(sequence.begin() + cut_point, sequence.end() - 1));
}

/**
 * 获取二叉树中所有和为目标值的节点路径。要求按照路径长度排序。
 */
vector<vector<int>> g_all_path{};
int g_max_path_length = 0;

void searchPath(TreeNode *node, vector<int> preVals, int expectNumber)
{
    // null node
    if (node == nullptr)
        return;
    // leaf node
    if (node->left == nullptr && node->right == nullptr)
    {
        if (expectNumber == node->val)
        {
            preVals.push_back(node->val);
            g_all_path.push_back(preVals);
            g_max_path_length = g_max_path_length > preVals.size() ? g_max_path_length : preVals.size();
        }
        return;
    }
    // other node
    preVals.push_back(node->val);
    searchPath(node->left, preVals, expectNumber - node->val);
    searchPath(node->right, preVals, expectNumber - node->val);
}

vector<vector<int>> ReorderSubVectors(vector<vector<int>> vec, int max_length)
{
    if (vec.size() < 2 || max_length == 1)
        return vec;
    vector<vector<int>> res{};
    for (int i = max_length; i >= 0; i--)
    {
        for (vector<int> v : vec)
        {
            if (i == v.size())
                res.push_back(v);
        }
    }
    return res;
}

vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
{
    if (root != nullptr)
        searchPath(root, vector<int>{}, expectNumber);
    // reorder
    g_all_path = ReorderSubVectors(g_all_path, g_max_path_length);
    return g_all_path;
}

void inorderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    cout << node->val << ' ';
    inorderTraversal(node->right);
}

void improvedInorTra(TreeNode *node, TreeNode **lastNodeInList)
{
    if (node == nullptr)
        return;

    TreeNode *curNode = node;
    improvedInorTra(curNode->left, lastNodeInList);
    curNode->left = *lastNodeInList;
    if (*lastNodeInList != nullptr)
        (*lastNodeInList)->right = curNode;
    *lastNodeInList = curNode;
    improvedInorTra(curNode->right, lastNodeInList);
}

TreeNode *Convert(TreeNode *pRootOfTree)
{
    if (pRootOfTree == nullptr)
        return nullptr;
    TreeNode *lastNode = nullptr;
    improvedInorTra(pRootOfTree, &lastNode);
    // lastNode指向中序最后一个节点，需要返回头结点
    while (lastNode->left != nullptr)
        lastNode = lastNode->left;

    return lastNode;
}

void dps_td(TreeNode *p, int cur, int &max)
{
    if (p == nullptr)
    {
        max = std::max(cur, max);
    }
    else
    {
        dps_td(p->left, cur + 1, max);
        dps_td(p->right, cur + 1, max);
    }
}

int TreeDeepth(TreeNode *pRoot)
{
    int res = 0;
    dps_td(pRoot, 0, res);
    return res;
}

// 采用了递归(On2)，应该有更省时间的方法
bool IsBalanced_Solution(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return true;
    int l = TreeDeepth(pRoot->left);
    int r = TreeDeepth(pRoot->right);
    if (abs(r - l) < 2)
        return true && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    else
        return false;
}

int calAllDeepth(TreeNode *p, unordered_map<TreeNode *, int> &map)
{
    if (p == nullptr)
        map[p] = 0;
    else
        map[p] = max(calAllDeepth(p->left, map), calAllDeepth(p->right, map)) + 1;
    return map[p];
}

bool doRec(TreeNode *p, unordered_map<TreeNode *, int> map)
{
    if (p == nullptr)
        return true;
    if (abs(map[p->left] - map[p->right]) < 2)
        return true && doRec(p->left, map) && doRec(p->right, map);
    return false;
}

// 采用map记录深度
bool IsBalanced_Solution_On(TreeNode *pRoot)
{
    unordered_map<TreeNode *, int> map;
    calAllDeepth(pRoot, map);
    return doRec(pRoot, map);
}

string getDiyOrderString(TreeNode *p, string diy)
{
    if (p == nullptr)
        return "";
    string s = to_string(p->val);
    string res;
    if (diy == "pre") // 左子树加 $ 右子树加 % -------- 处理相同的左右子树val
        res = s + "#" + getDiyOrderString(p->left, "pre") + "$" + getDiyOrderString(p->right, "pre") + "%";
    if (diy == "bp") // 左子树加 % 右子树加 $
        res = s + "#" + getDiyOrderString(p->right, "bp") + "$" + getDiyOrderString(p->left, "bp") + "%";
    if (diy == "mid")
        res = getDiyOrderString(p->left, "mid") + "$" + s + "#" + getDiyOrderString(p->right, "mid") + "%";
    if (diy == "bm")
        res = getDiyOrderString(p->right, "bm") + "$" + s + "#" + getDiyOrderString(p->left, "bm") + "%";
    return res;
}

// 镜像二叉树

bool isSymmetrical(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return true;

    string pre = getDiyOrderString(pRoot, "pre");
    string bp = getDiyOrderString(pRoot, "bp");
    string mid = getDiyOrderString(pRoot, "mid");
    string bm = getDiyOrderString(pRoot, "bm");
    cout << pre << endl
         << bp << endl;
    return (pre == bp) && (mid == bm);
}

// 按行输出
vector<vector<int>> Print_byline(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return vector<vector<int>>{};
    TreeNode *end = pRoot, *top;
    vector<vector<int>> res;
    vector<int> line;
    queue<TreeNode *> q;
    q.push(pRoot);
    while (!q.empty() && end != nullptr)
    {
        top = q.front();
        q.pop();
        line.push_back(top->val);
        if (top->left != nullptr)
            q.push(top->left);
        if (top->right != nullptr)
            q.push(top->right);
        if (top == end)
        {
            if (!line.empty())
                res.push_back(line);
            line.clear();
            end = q.back();
        }
    }
    return res;
}

// 之字形
vector<vector<int>> Print(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return vector<vector<int>>{};

    vector<vector<int>> res;
    vector<int> line;
    queue<TreeNode *> q;
    TreeNode *p = pRoot, *end = pRoot;
    bool reverse = false;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        line.push_back(p->val);
        if (p->left != nullptr)
            q.push(p->left);
        if (p->right != nullptr)
            q.push(p->right);
        if (p == end)
        {
            if (reverse)
                std::reverse(line.begin(), line.end());
            reverse = !reverse;
            res.push_back(line);
            line.clear();
            end = q.back();
        }
    }

    return res;
}

/**
 * 二叉树的序列化和反序列化
 */
void doSerialize(TreeNode *node, char *&s)
{
    if (node == nullptr)
    {
        *(s++) = '#';
        return;
    }
    string num = to_string(node->val);
    for (char c : num)
    {
        *(s++) = c;
    }
    *(s++) = '!';
    doSerialize(node->left, s);
    doSerialize(node->right, s);
}

char *Serialize(TreeNode *root)
{
    char *s = new char[1000];
    char *p = s;
    doSerialize(root, p);
    *p = '\0';
    return s;
}

vector<string> to_vec(char *c)
{
    vector<string> v{};
    string s = "";
    while (*c != '\0')
    {
        if (*c == '#')
        {
            v.push_back("#");
        }
        else if (*c == '!')
        {
            v.push_back(s);
            s = "";
        }
        else
        {
            s += *c;
        }
        c++;
    }
    return v;
}

TreeNode *doDeserialize(vector<string> vec, int &i)
{
    if (i >= vec.size() || vec[i] == "#")
    {
        i++;
        return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(vec[i++]));
    node->left = doDeserialize(vec, i);
    node->right = doDeserialize(vec, i);
    return node;
}

TreeNode *Deserialize(char *s)
{
    vector<string> vec = to_vec(s);
    int i = 0;
    TreeNode *node = doDeserialize(vec, i);
    return node;
}

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    if (pNode == nullptr)
        return nullptr;
    TreeLinkNode *p = pNode;
    if (p->right != nullptr)
    { // 当前节点有右子树
        p = p->right;
        while (p->left != nullptr)
            p = p->left;
        return p;
    }
    while (p->next != nullptr)
    {
        if (p->next->left == p)
            break;
        else
            p = p->next;
    }
    return p->next;
}

void findKth(TreeNode *p, int &i, int k, TreeNode *&res)
{
    if (p == nullptr || res != nullptr)
        return;

    findKth(p->left, i, k, res);
    if (++i == k)
    {
        res = p;
        return;
    }
    findKth(p->right, i, k, res);
}

TreeNode *KthNode(TreeNode *pRoot, int k)
{
    int i = 0;
    TreeNode *p = nullptr;
    findKth(pRoot, i, k, p);
    return p;
}

int main()
{
    TreeNode *head = reConstructBinaryTree(vector<int>{5, 3, 2, 4, 7, 6, 8}, vector<int>{2, 3, 4, 5, 6, 7, 8});
    TreeNode *p = KthNode(head, 5);
    cout << p->val;
    return 0;
}