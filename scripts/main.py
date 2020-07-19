#!/usr/bin/python3
import ctypes                   # Used to get c functions
import os
import sys
import unittest   
from hypothesis import given
import hypothesis.strategies as st

        		         # testing framework
from unittest.mock import MagicMock, Mock # mocking framework

try:
    libtesting = ctypes.CDLL(os.path.dirname(__file__)+"/../build/libtesting_test.so")
except OSError:
    print("Please put the .so in a build directory")
    sys.exit()

# Python implimentation of the C++ class
class Ccx(ctypes.Structure):
    pass

class IntCx(object):
    def __init__(self):
        self._ptr = libtesting.create_cx() # this is calling the c function ```create_cx()```

    def callPublic(self):
        return libtesting.call_public(self._ptr)

# pull in the c functions
# need to define argtypes (inputs) and restype (output)
# call public is a function in the testing function, defines arg types, resrtpe does the return type 
# 
libtesting.create_cx.argtypes = []
libtesting.create_cx.restype = ctypes.POINTER(Ccx)

libtesting.call_public.argtypes = [ctypes.POINTER(Ccx)]
libtesting.call_public.restype = ctypes.c_int

libtesting.outside_function.argtypes = []
libtesting.outside_function.restype = ctypes.c_int

libtesting.inside_function.argtypes = []
libtesting.inside_function.restype = ctypes.c_int

libtesting.add_two_ints.argtypes = [ctypes.c_int,ctypes.c_int]
libtesting.add_two_ints.restype = ctypes.c_int

# unittest framework for testing
class TestIntCx(unittest.TestCase):

    def setUp(self):
        self.cx = IntCx()



    # testing the call public C++ method
    def test_call_public(self):
        self.assertEqual(self.cx.callPublic(), 1)
        # Can't test the rest of the code coverage because its within
        # a private method...
        self.assertEqual(self.cx.callPublic(), 0)

    # testing the ```inside_function()```
    def test_call_inside_function(self):
        self.assertEqual(libtesting.inside_function(), 1)

    # testing the ```outside_function()```
    def test_call_outside_function(self):
        self.assertEqual(libtesting.outside_function(), 1)

        # since the internal function is in c, it can't be mocked in
        # Python
        mock0 = Mock(libtesting.inside_function(), return_value=0)
        self.assertEqual(libtesting.outside_function(), 0)
        
    @given(st.integers(min_value = -200,max_value = 200), st.integers(min_value = -200, max_value = 200))
    def test_add_two_ints(self, x, y):
        self.assertEqual(libtesting.add_two_ints(x,y), x+y)                    

if __name__ == "__main__":
    unittest.main()
