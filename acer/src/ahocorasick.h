#ifndef AHOCORASICK
#define AHOCORASICK

#include <iostream>
#include "trie_tree.h"

using namespace std;

class AhoCorasick: public TrieTree {
    unordered_map <int, Node*> failure;
    time_t start,stop;
    public:
    void insert(string word, bool if_reverse=false);
    void checkout(Node* &root, vector<string> &result,const int &stop);
    vector<string> search_(vector<string> &segments);
    //void search(string text);
    vector<string> search(string text, bool if_reverse=false);
    vector<string> search(vector<string> segments);
    void make_ac();
};
#endif