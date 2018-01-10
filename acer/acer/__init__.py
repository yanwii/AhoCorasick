# -*- coding:utf-8 -*-
import acer

class AhoCorasick:
    def __init__(self):
        self.ac = acer.AhoCorasick()

    def add_word(self, word, if_reverse=false):
        self.ac.add_word(word)