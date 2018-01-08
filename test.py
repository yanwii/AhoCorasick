# -*- coding:utf-8 -*-
import ahocorasick

ac = ahocorasick.AhoCorasick()
ac.add_word("he", True)
ac.make_ac()
ac.search("sdfhes", True)