#include <iostream>
#include <vector>
#include <fstream>
#include "utils.h"
using namespace std;

vector<vector<string>> cut(vector<string> keywords){
    vector<vector<string>> result;
    for (string word:keywords){
        try{
            vector<string> cut_word = cut(word);
            result.push_back(cut_word);
        } catch (exception& e){
            continue;        
        }
    }
    return result;
};

vector<string> cut(const string &word){
    vector<string> segements;
    string tmp = "";
    for (int i=0; i < word.size(); i++){
        if(word.at(i) <= -1){
            tmp = "";
            tmp += word.at(i);
            i++;
            tmp += word.at(i);
            i++;
            tmp += word.at(i);
            segements.push_back(tmp);
        } else {
            tmp = word.at(i);
            segements.push_back(tmp);
        }
    }
    return segements;
}

vector<string> read_file(string file_name){
    ifstream ifs(file_name, ifstream::in);
    string line;
    vector<string> company_names;
    while(getline(ifs, line)){
        company_names.push_back(line);
    }
    ifs.close();
    return company_names;
}