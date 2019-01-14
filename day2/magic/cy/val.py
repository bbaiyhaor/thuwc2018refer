# encoding: utf-8

import os, sys, re

def run(index, type):
    print 'processing', index

    input = ''
    answer = ''
    if index < 0:
        input = '../down/%d.in' % (-index)
        answer = '../down/%d.ans' % (-index)
    else:
        input = '../data/%d.in' % index
        answer = '../data/%d.ans' % index
    
    assert os.system('./val.exe %d < %s' % (type, input)) == 0
    assert os.system('cp %s magic.in' % input) == 0
    assert os.system('./segtree.exe') == 0
    assert os.system('diff magic.out %s' % answer) == 0

if __name__ == '__main__':
    run(-1, 1)
    run(-2, 1)

    run(1, 1)
    run(2, 1)

    run(3, 2)
    run(4, 2)

    run(5, 3)
    run(6, 3)

    run(7, 4)
    run(8, 4)

    run(9, 5)
    run(10, 5)
    run(11, 5)

    run(12, 6)
    run(13, 6)
    run(14, 6)

    run(15, 7)
    run(16, 7)
    run(17, 7)

    run(18, 8)
    run(19, 8)
    run(20, 8)