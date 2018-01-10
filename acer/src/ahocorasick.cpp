#include <iostream>
#include <vector>
#include <unordered_map>
#include <exception>
#include <time.h>
#include <algorithm>
#include <deque>
#include "trie_tree.h"
#include "utils.h"
#include "ahocorasick.h"

using namespace std;
void AhoCorasick::make_ac(){
    deque <Node *> q;
    Node* root = proot;
    Node* parent_failure_node;
    q.push_back(root);

    while(!q.empty()){
        //root = pop_back(queue);
        root = q.front();
        q.pop_front();
        int parent_state = root->state;
        for (auto it=root->child.begin(); it!=root->child.end();it++){
            string word = it->first;
            Node* node = it->second;
            q.push_back(node);
            //cout << "word " << word << " state " << node->state;
            //cout << " parent_word " << parent_state << endl;
            int state = node->state;
            
            if (node->depth==1){
                failure[state] = proot;
                continue;
            }
            parent_failure_node = failure[parent_state];
            if (parent_failure_node->child[word]!=NULL){
                failure[state] = parent_failure_node->child[word];
                //cout << state << " failure state " << parent_failure_node->child[word]->state << endl;
            } else {
                failure[state] = proot;
            }
        }
    }
}

//void AhoCorasick::search(string text){
//    search(text, false);
//}

vector<string> AhoCorasick::search(string text, bool if_reverse){
    vector<string> segment = cut(text, if_reverse);
    return search_(segment);
    
}

vector<string> AhoCorasick::search(vector<string> segements){
    cout << &segements << endl;
}

vector<string> AhoCorasick::search_(vector<string> &segments){
    vector<string> result;
    Node* root = proot;
    for (int i=0 ; i < segments.size(); i++){
        string seg = segments[i];
        //cout << seg << endl;
        //cout << root->state << endl;
        //cout << root->is_end << endl;
        if (root->child[seg]==NULL){
            if (root->state==0){
                root = proot;
                continue;
            } else {
                root = failure[root->state];
                checkout(root, result, i+1);
                i--;
            }
        } else {
            root = root->child[seg];
            checkout(root, result, i+1);
        }
        //
    }
    return result;
}

void AhoCorasick::checkout(Node* &root, vector<string> &result,const int &stop){
    if (root->is_end){
        string text = root->segment;
        int start = stop - cut(text, true).size();
        string from_to = to_string(start) + "_" + to_string(stop);
        result.push_back(from_to);
    }            
}


void AhoCorasick::insert(string word, bool if_reverse){
    try{
        vector<string> segment = cut(word, if_reverse);
        string tmp = "";
        Node* root = proot;
        for (int i=0; i<segment.size(); i++){
            string word = segment[i];
            tmp += word;
            if (root->child[word]==NULL){
                node_nums ++;
                root->child[word] = new Node();
                root->child[word]->word = word;
                root->child[word]->state = node_nums;
                root->child[word]->depth = i+1;
            }
            
            int depth = root->child[word]->depth;
            int state = root->child[word]->state;
            if (depth<=1){
                failure[root->child[word]->state] = proot;
            } else {
                int parent_state = root->state;
                Node* parent_failure_node = failure[parent_state];
                if (parent_failure_node->child[word]!=NULL){
                    failure[state] = parent_failure_node->child[word];
                    //cout << state << " failure state " << parent_failure_node->child[word]->state << endl;
                } else {
                    failure[state] = proot;
                }
            }
            root = root->child[word];
        }
        root->is_end = true;
        root->segment = tmp;
    } catch (exception &e){
        cout << &e << endl;
    }
}


int main(){
    AhoCorasick ac;
    //vector<string> words = read_file("/home/ubuntu/SocialCredits/CompanyName/company_names.txt");
    vector<string> words = read_file("test.txt");
    cout << "Found " << words.size() << " entities " << endl;
    
    time_t start,stop;
    start = time(NULL);
    ac.add_words(words, true);
    stop = time(NULL);
    cout << "make trie tree cost: "<< stop - start << endl;

    start = time(NULL);
    ac.make_ac();
    stop = time(NULL);
    cout << "make failure tree cost: " << stop - start << endl;

    vector<string> inputs = cut("石家庄福华房地产开发有限公司", true);
    ac.search_(inputs);


    ac.insert("阿里巴巴", true);
    inputs = cut("阿里巴巴", true);
    ac.search_(inputs);


    char str1[10], str2[10];
    cin>>str1;
}