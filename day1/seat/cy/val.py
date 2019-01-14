# encoding: utf-8

import os, sys, re
import json

def run(index, maxn, maxm):
    print 'processing', index, maxn, maxm

    input = ''
    output = ''
    STD = './70pts.exe'

    if index < 0:
        input = '../down/%d.in' % (-index)
        output = '../down/%d.ans' % (-index)
    else:
        input = '../data/%d.in' % (index)
        output = '../data/%d.ans' % (index)
    
    assert os.system('./val.exe %d %d < %s' % (maxn, maxm, input)) == 0
    assert os.system('cp %s seat.in' % input) == 0
    assert os.system(STD) == 0
    assert os.system('diff seat.out %s' % output) == 0

if __name__ == '__main__':
    run(-1, 2, 10)
    run(-2, 2, 10)
    run(-3, 2, 10)
    run(-4, 40, 10)

    data = json.loads(open('../conf.json').read())['data']
    maxn = 0
    maxm = 0
    for d in data:
        if 'n' in d['args']:
            maxn = d['args']['n']
        if 'm' in d['args']:
            maxm = d['args']['m']
        for i in d['cases']:
            run(i, maxn, maxm)