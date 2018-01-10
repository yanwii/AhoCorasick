#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "utils.h"
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
using namespace std;
using namespace boost::python;

vector<string> cut(const string &word, bool if_reverse=false){
    vector<string> segments;
    string tmp = "";
    for (int i=0; i < word.size(); i++){
        if(word.at(i) <= -1){
            tmp = "";
            tmp += word.at(i);
            i++;
            tmp += word.at(i);
            i++;
            tmp += word.at(i);
            segments.push_back(tmp);
        } else {
            tmp = word.at(i);
            segments.push_back(tmp);
        }
    }
    if (if_reverse){
        reverse(segments.begin(), segments.end());
    }
    return segments;
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
