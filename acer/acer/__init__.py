# -*- coding:utf-8 -*-
import acer

class Acer:
    def __init__(self):
        self.ac = acer.AhoCorasick()

    def add_word(self, word, if_reverse=False):
        self.ac.add_word(word, if_reverse)

    def make_ac(self):
        self.ac.make_ac()

    def search(self, sentence, if_reverse=False):
        result = self.ac.search(sentence, if_reverse)
        real_result = self.format_out(result, sentence)
        return {"entities":real_result}

    def insert(self, word):
        self.ac.insert(word)

    def format_out(self, result, sentence):
        real_result = []        
        if isinstance(sentence, str):
            sentence = sentence.decode("utf-8")
        try:
            for index in list(result):
                begin, end = [int(i) for i in index.split("_")]
                word = sentence[begin:end]
                real_result.append({"begin":begin, "end":end, "word":word.encode("utf-8")})
        except Exception,e:
            print e
            pass
        return real_result
        