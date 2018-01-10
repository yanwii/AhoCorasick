#!/usr/bin/env python  
  
from distutils.core import setup, Extension  
  

# the c++ extension module
extension_mod = Extension("acer", 
                        sources=['acer/src/acer.cpp', 'acer/src/ahocorasick.cpp', 'acer/src/trie_tree.cpp', 'acer/src/utils.cpp'],
                        include_dirs=['acer/include'],
                        library_dirs=['acer/include/boost'],
                        runtime_library_dirs=['acer/include/boost'],
                        libraries=['boost_python'],
                        extra_compile_args=['-std=c++11'])

setup(name='acer',
      version='0.1',
      description='Test',
      ext_modules=[extension_mod])