#include <string>
#include <iostream>
#include <vector>
#include "ahocorasick.h"
#include "trie_tree.h"
#include <boost/python.hpp>
using namespace boost::python;
using namespace std;
typedef string ST;

// overloadings
void    (AhoCorasick::*search1)(vector<ST>) = &AhoCorasick::search;
void    (AhoCorasick::*search2)(string, bool) = &AhoCorasick::search;


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(search_overloads, search, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(add_word_overloads, add_word, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(insert_overloads, insert, 1, 2)
BOOST_PYTHON_MODULE(acer)
{   
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


