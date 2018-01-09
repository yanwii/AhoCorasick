# -*- coding:utf-8 -*-
import pandas as pd
import acer

df = pd.read_table("test.txt")
df.columns = ['org']
print df.head()
ac = acer.AhoCorasick()
for i in df['org'].tolist():
    ac.add_word(i, True)
ac.search("天津福宾商务宾馆有限公司", True)
