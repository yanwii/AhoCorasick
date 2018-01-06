g++ -std=c++11 -c trie_tree.cpp
g++ -std=c++11 -c utils.cpp
g++ -std=c++11 -c ahocorasick.cpp
g++ -std=c++11 -o main ahocorasick.o trie_tree.o utils.o

rm *.o