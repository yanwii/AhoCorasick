#!/usr/bin/env python  
  
from distutils.core import setup, Extension  
  

# the c++ extension module
extension_mod = Extension("Extest", ["ahocorasick.cpp"])

setup(name = "Extest", ext_modules=[extension_mod])