#include <iostream>
#include <vector>
#include <unordered_map>
#include <exception>
#include <time.h>
#include <algorithm>
#include <queue>
#include "trie_tree.h"
#include "utils.h"

using namespace std;
class AhoCorasick:public TrieTree{
    unordered_map <int, Node*> failure;
    public:
    time_t start,stop;

    void make_ac(){
        queue<Node *> q;
        Node* root = proot;
        Node* parent_failure_node;
        q.push(root);
        
        while(!q.empty()){
            //root = pop_back(queue);
            root = q.front();
            q.pop();
            int parent_state = root->state;
            for (auto it=root->child.begin(); it!=root->child.end();it++){
                string word = it->first;
                Node* node = it->second;
                q.push(node);
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
    void search(vector<string> &segments){
        unordered_map<string, string> result;
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
        for (auto it=result.begin(); it!=result.end(); it++){
            cout << "from_to " << it->first << " word " << it->second << endl;
        }
    }

    void checkout(Node* &root, unordered_map<string, string> &result,const int &stop){
        if (root->is_end){
            string text = root->segment;
            int start = stop - cut(text).size();
            string from_to = to_string(start) + "_" + to_string(stop);
            result[from_to] = text;
        }            
    }

    Node* pop_back(vector<Node*> &queue){
        Node* root = queue[0];
        queue.erase(queue.begin());
        return root;
    }
};
int main(){
    AhoCorasick ac;
    //vector<string> words = read_file("/home/ubuntu/SocialCredits/CompanyName/company_names.txt");
    vector<string> words = read_file("test.txt");
    cout << "Found " << words.size() << " entities " << endl;
    
    time_t start,stop;
    start = time(NULL);
    ac.add_words(words, true);
    stop = time(NULL);
    cout << stop - start << endl;

    
    start = time(NULL);
    ac.make_ac();
    stop = time(NULL);
    cout << stop - start << endl;

    vector<string> inputs = cut("石家庄福华房地产开发有限公司");
    reverse(inputs.begin(), inputs.end());
    ac.search(inputs);
    char str1[10], str2[10];
    cin>>str1;
}