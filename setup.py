#!/usr/bin/env python  
  
from distutils.core import setup, Extension  
  

# the c++ extension module
extension_mod = Extension("acer", 
                        sources=['src/acer/acer.cpp', 'src/acer/ahocorasick.cpp', 'src/acer/trie_tree.cpp', 'src/acer/utils.cpp'],
                        include_dirs=['src/include/python2.7'],
                        library_dirs=['src/include/boost'],
                        runtime_library_dirs=['src/include/boost'],
                        libraries=['boost_python'],
                        extra_compile_args=['-std=c++11'])

setup(name='acer',
      version='0.1',
      description='Test',
      ext_modules=[extension_mod])