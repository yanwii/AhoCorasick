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
            add_word(words[i], if_reverse);
        } catch (exception &e){
            continue;
        }
    }
}


void TrieTree::add_word(string word, bool if_reverse){
    /*
    Add word to Trie Tree

    args:
        words:      vector<string>;
                    like {"s", "h", "s"}
        if_reverse: bool;
                    if reverse the segment
    */
    try {
        vector<string> words = cut(word, if_reverse);

        //root node
        Node* root = proot; 
        string tmp = "";

        //reverse
        for (int i=0; i<words.size(); i++){
            string word = words[i];
            if (vocab[word]==0){
                vocab[word] = vocab.size()+1;
            }
            int word_to_int = vocab[word];

            tmp += words[i];
            // check if the node exist
            if (root->child[word_to_int]==NULL){
                // if not exist
                // add new node
                node_nums++;
                root->child[word_to_int] = new Node();
                root->child[word_to_int]->word = word;
                root->child[word_to_int]->state = node_nums;
                root->child[word_to_int]->depth = i+1;
            };
            // goto child node
            root = root->child[word_to_int];
        }
        root->is_end = true;
        root->segment = tmp;
    } catch (exception &e){}
};





