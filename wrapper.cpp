#include <string>
#include <iostream>
#include <vector>
#include "ahocorasick.h"
#include "trie_tree.h"

#include <boost/python.hpp>
using namespace boost::python;
BOOST_PYTHON_MODULE(ahocorasick)
{   
    class_<TrieTree>("TrieTree")
        .def("add_words", &TrieTree::add_words)
        .def("add_word", &TrieTree::add_word);
    
    class_<AhoCorasick, bases<TrieTree>>("AhoCorasick")
        .def("insert", &AhoCorasick::insert)
        .def("make_ac", &AhoCorasick::make_ac)
        .def("search", &AhoCorasick::search)
        .def("search_", &AhoCorasick::search_);
        
}


