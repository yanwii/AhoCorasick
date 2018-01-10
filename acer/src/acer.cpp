#include <string>
#include <iostream>
#include <vector>
#include "ahocorasick.h"
#include "trie_tree.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
using namespace boost::python;
using namespace std;
typedef string ST;

// overloadings
vector<string>    (AhoCorasick::*search1)(vector<ST>) = &AhoCorasick::search;
vector<string>    (AhoCorasick::*search2)(string, bool) = &AhoCorasick::search;


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(search_overloads, search, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(add_word_overloads, add_word, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(insert_overloads, insert, 1, 2)
BOOST_PYTHON_MODULE(acer)
{   
    class_<vector<string> >("string_vector")
        .def(vector_indexing_suite<vector<string> >());


    class_<TrieTree>("TrieTree")
        .def("add_words", &TrieTree::add_words)
        .def("add_word", &TrieTree::add_word, add_word_overloads());
    
    class_<AhoCorasick, bases<TrieTree>>("AhoCorasick")
        .def("insert", &AhoCorasick::insert, insert_overloads())
        .def("make_ac", &AhoCorasick::make_ac)
        .def("search", search1)
        .def("search", search2, search_overloads())
        .def("search_", &AhoCorasick::search_);
}


