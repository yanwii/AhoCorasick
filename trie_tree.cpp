#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <exception>
#include "utils.h"
#include "trie_tree.h"
using namespace std;


void TrieTree::add_words(vector<string> &words, bool if_reverse=false){
    for (int i=0; i<words.size(); i++){
        try {
            string seg = words[i];
            vector<string> segment = cut(seg);
            if (if_reverse){
                reverse(segment.begin(), segment.end());
            }
            Node* root = proot;
            string tmp = "";
            for (int i=0; i<segment.size(); i++){
                string word = segment[i];
                tmp += segment[i];
                if (root->child[word]==0){
                    node_nums++;
                    index ++;
                    root->child[word] = new Node();
                    root->child[word]->word = word;
                    root->child[word]->state = index;
                    root->child[word]->depth = i+1;
                };
                root = root->child[word];
                /*
                string depth_seg = word + "_" + to_string(i+1);

                if (depth_to_node[depth_seg]==NULL){
                    node_nums++;
                    index ++;
                    root->child[word] = new Node();
                    root->child[word]->word = word;
                    root->child[word]->state = index;
                    root->child[word]->depth = i+1;
                    depth_to_node[depth_seg] = root;
                }
                root = depth_to_node[depth_seg];
                */

            }
            root->is_end = true;
            root->segment = tmp;
            //cout << float(i) /words.size()*100 << endl;
        } catch (exception &e){
            continue;
        }
    }
    cout << "node nums: " << node_nums << endl;
};




void TrieTree::prefix_search(string &text){
    vector<string> cut_text = cut(text);
    Node* root = proot;
    for (int i=0; i < cut_text.size(); i++){
        string seg = cut_text[i];
        if (root->child[seg]==0){
            break;
        }
        if (root->child[seg]->is_end){
            cout << root->child[seg]->segment << endl;
        }
        root = root->child[seg];
    }
};

