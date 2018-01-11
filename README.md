# AhoCorasick
In computer science, the Aho–Corasick algorithm is a string searching algorithm invented by Alfred V. Aho and Margaret J. Corasick.
It is a kind of dictionary-matching algorithm that locates elements of a finite set of strings (the "dictionary") within an input text. It's based on a **Trie Tree** which is a dictonary tree.

# Install

    pip2 install acer

# Use

    import acer

    ac = acer.Acer()

    # add word
    ac.add_word("he")   
    ac.add_word("she")   
    ac.add_word("her")
    
    # then make failure tree
    ac.make_ac()

    # search
    ac.search("ushers")

    # insert
    ac.insert("his")


### NOTICE
After you making the failure tree, if you insert a word into trie tree, the failure tree could be imcomplete because the first char of new word could be the failure state of a word which already exist.  
Such as:  
Add the word "add" first, and then make failure tree  
Now insert the "desert", the char "d" in "desert" should have been the failure state of "d" in "add", but it's not work because of the order.  

So, after you insert a word, re-making failure tree will be recommended.  