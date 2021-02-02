#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    int path;
    int end;
    unordered_map<char, TrieNode*> map;
    TrieNode() : path(0), end(0) {}
};

class Trie{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        if(word == "") return;
        TrieNode* node = root;
        for(char c : word){
            if(node->map.find(c) == node->map.end())
                node->map[c] = new TrieNode();
            node = node->map[c];
            node->path++;
        }
        node->end++;
    }

    void del(string word)
    {
        if(search(word))
        {
            TrieNode * p = root;
            for(char c : word){
                if(p->map[c]->path == 1){
                    p->map.erase(c);
                    return;
                }else{
                    p = p->map[c];
                    p->path--;
                }
            }
            p->end--;
        }
    }

    bool search(string word)
    {
        if(word == "") return false;
        TrieNode* node = root;
        for(char c : word){
            if(node->map.find(c) == node->map.end())
                return false;
            node = node->map[c];
        }
        return node->end != 0;
    }

    int countStartsWith(string prefix)
    {
        if(prefix == "") return 0;
        TrieNode* node = root;
        for(char c : prefix){
            if(node->map.find(c) == node->map.end())
                return 0;
            node = node->map[c];
        }
        return node->path;
    }

    bool startsWith(string prefix)
    {
        if(prefix == "") return false;
        TrieNode* node = root;
        for(char c : prefix){
            if(node->map.find(c) == node->map.end())
                return false;
            node = node->map[c];
        }
        return node->path != 0;
    }

};

int main()
{
    Trie* trie = new Trie();
    trie->insert("abc");
    trie->insert("abcd");
    trie->insert("bcd");
    trie->insert("ae");
    
    trie->del("abc");
    cout << trie->search("abc")<<trie->search("abcd");

    return 0;
}