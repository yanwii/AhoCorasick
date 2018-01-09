#ifndef AHOCORASICK
#define AHOCORASICK

#include <iostream>
#include "trie_tree.h"

using namespace std;

class AhoCorasick: public TrieTree {
    unordered_map <int, Node*> failure;
    time_t start,stop;
    public:
    void insert(string word, bool if_reverse);
    void checkout(Node* &root, unordered_map<string, string> &result,const int &stop);
    void search_(vector<string> &segments);
    //void search(string text);
    void search(string text, bool if_reverse=false);
    void search(vector<string> segments);
    void make_ac();
};
#endif