#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <exception>
#include "utils.h"
#include "trie_tree.h"
using namespace std;


void TrieTree::add_words(vector<string> &words, bool if_reverse){
    /*
    Add words to Trie Tree

    args:
        words     :  vector<string> 
                     like {"she", "he"}
        if_reverse:  bool
                     if reverse the segment
    */
    vector<string> seg;
    for (int i=0; i < words.size(); i++){
        try{
            seg = cut(words[i], if_reverse);
            add_word(seg);
        } catch (exception &e){
            continue;
        }
    }
}


void TrieTree::add_word(vector<string> &words){
    /*
    Add word to Trie Tree

    args:
        words:      vector<string>;
                    like {"s", "h", "s"}
        if_reverse: bool;
                    if reverse the segment
    */
    try {
        //root node
        Node* root = proot; 
        string tmp = "";

        //reverse
        for (int i=0; i<words.size(); i++){
            string word = words[i];
            tmp += words[i];
            // check if the node exist
            if (root->child[word]==NULL){
                // if not exist
                // add new node
                node_nums++;
                root->child[word] = new Node();
                root->child[word]->word = word;
                root->child[word]->state = node_nums;
                root->child[word]->depth = i+1;
            };
            // goto child node
            root = root->child[word];
        }
        root->is_end = true;
        root->segment = tmp;
    } catch (exception &e){}
};





