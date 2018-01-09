# -*- coding:utf-8 -*-
import ahocorasick
import pandas as pd


df = pd.read_table("test.txt")
df.columns = ['org']
print df.head()
ac = ahocorasick.AhoCorasick()
for i in df['org'].tolist():
    ac.add_word(i)
ac.search("天津福宾商务宾馆有限公司")
