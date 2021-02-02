#include <bits/stdc++.h>
using namespace std;

class Node{
public :  
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr){}
};

class DoubleNodeList{
private : 
    Node* head;
    Node* tail;

public :
    DoubleNodeList() : head(nullptr), tail(nullptr) {};
    
    void add(Node* node){
        if(head == nullptr){
            head =  node;
            tail = node;
        }else{
            tail->right = node;
            node->left = tail;
            tail = node;
        }
    }

    Node* removeHead(){
        if(head == nullptr){
            return nullptr;
        }else{
            Node* res = head;
            if(head == tail){
                head = nullptr;
                tail = nullptr;
            }else{
                head = head->right;
                res->right = nullptr;
                head->left = nullptr;
            }
            return res;
        }
    }

    void moveNodeToTail(Node* node){
        if(node == tail){
            return;
        }
        if(node == head){
            head = node->right;
            head->left = nullptr;
        }else{
            node->left->right = node->right;
            node->right->left = node->left;
        }
        tail->right = node;
        node->left = tail;
        node->right = nullptr;
        tail = node;
    }
};

class LRUCache{
private :
    int capacity;
    unordered_map<int, Node*> key2node;
    unordered_map<Node*, int> node2key;
    DoubleNodeList nodelist;

public :  
    LRUCache(int cap){
        capacity = cap;
    }

    int get(int key){
        if(key2node.find(key) == key2node.end()){
            return -1;
        }else{
            nodelist.moveNodeToTail(key2node[key]);
            return key2node[key]->val;
        }
    }

    void put(int key, int value){
        if(key2node.find(key) == key2node.end()){
            Node* node = new Node(value);
            key2node[key] = node;
            node2key[node] = key;
            nodelist.add(node);
            if(key2node.size() == capacity+1){
                Node* del = nodelist.removeHead();
                key2node.erase(node2key[del]);
                node2key.erase(del);
            }
        }else{
            key2node[key]->val = value;
            nodelist.moveNodeToTail(key2node[key]);
        }
    }
};