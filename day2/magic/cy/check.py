# encoding: utf-8

import os, sys, re
import random

def make():
    N = 5
    M = 5

    f = open('magic.in', 'w')
    
    f.write('%d\n' % N)
    for i in range(N):
        f.write('%d %d %d\n' % (random.randint(0, 10), random.randint(0, 10), random.randint(0, 10)))
    f.write('%d\n' % M)
    for i in range(M):
        opt = random.randint(1, 7)
        l = random.randint(1, N)
        r = random.randint(1, N)
        v = random.randint(0, 10)
        if l > r:
            t = l
            l = r
            r = t
        
        if 4 <= opt and opt <= 6:
            f.write('%d %d %d %d\n' % (opt, l, r, v))
        else:
            f.write('%d %d %d\n' % (opt, l, r))

    f.close()

if __name__ == '__main__':

    while True:
        make()

        assert os.system('./brute.exe') == 0
        assert os.system('cp magic.out brute.out') == 0
        assert os.system('./segtree.exe') == 0
        assert os.system('cp magic.out segtree.out') == 0
        assert os.system('diff segtree.out brute.out') == 0