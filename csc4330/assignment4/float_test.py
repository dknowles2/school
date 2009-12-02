#!/usr/bin/python

import re
import unittest


class Test(unittest.TestCase):

    floats = [
        '0.',
        '0.0',
        '0.00',
        '0.0e1',
        '0.00e1',
        '00.0e1',
        '00.0e11',
        '0.00e11',
        '00.00e11',
        '0.0e+1',
        '0.0e+11',
        '0.0e-1',
        '0.0e-11',

        '0.0E1',
        '0.00E1',
        '00.0E1',
        '0.0E11',
        '00.00E1',
        '00.00E11',
        '0.0E+1',
        '0.0E+11',
        '0.0E-1',
        '0.0E-11',

        '.0',
        '.00',
        '.00e1',
        '.00E1',
        '.0e1+1',
        '.0e1-1',
        '.0E1-1',
        ]

    def doTest(self, pattern):
        float_re = re.compile(pattern)
        for n in self.floats:
            print n
            self.assertTrue(float_re.match(str(n)))

    def testA(self):
        pattern = r'(\d*\.\d+|\d+\.)|(\d+|(\d*\.\d+|\d+\.))[eE][+-]?\d+'
        self.doTest(pattern)

    def testB(self):
        pattern = r'(\d*\.\d+|\d+\.)([eE][+-]?\d+)?|\d+[eE][+-]?\d+'
        pattern = r'\d*\.\d+|\d+\.([eE][+-]?\d+)?|\d+[eE][+-]?\d+'
        self.doTest(pattern)


def doUnicode():
    print ur"hello \u03b2 world"


def arrAddr():
    addr = 1000

    for i in range(0, 4):
        for j in range(0, 5):
            for k in range(0, 3):
                print '%s: %d %d %d' % (addr, i, j, k)
                addr += 4



if __name__ == '__main__':
    #arrAddr()
    #print
    unittest.main()
