# encoding: utf-8

import os, sys, re

def run(index, n, m, seed):
    print 'processing', index

    input = ''
    answer = ''
    STD = '../cy/100pts.exe'

    if index < 0:
        input = '../down/%d.in' % (-index)
        answer = '../down/%d.ans' % (-index)
    else:
        input = '../data/%d.in' % (index)
        answer = '../data/%d.ans' % (index)
    
    assert os.system('./random.exe %d %d %s > seat.in' % (n, m, seed)) == 0
    assert os.system('cp seat.in %s' % input) == 0
    assert os.system(STD) == 0
    assert os.system('cp seat.out %s' % answer) == 0

if __name__ == '__main__':
    run(-3, 2, 10, 'sd123dq2d1')
    run(-4, 40, 9, '231edwecx2')

    run(1, 2, 9, 'd32dxc123d23')
    run(2, 2, 10, 'f32dc2c32ef')

    run(3, 40, 8, 'f34c234f43')
    run(4, 40, 9, 'b54b34f3f')
    run(5, 40, 9, 'g435gh543v23')
    run(6, 40, 10, 'g354c2f3')
    run(7, 40, 10, '5h4vb543v435')
    run(8, 40, 10, 'gg43vcf34f43')

    run(9, 100, 10, '6uh4gb54g')
    run(10, 100, 10, '543gv34v54')
    run(11, 100, 10, '67uj5b54')
    run(12, 100, 10, 'g54v4g54')
    run(13, 99, 10, '7ui6n5b54h54tvwerfg')
    run(14, 99, 10, 'v34c24f54yh54tbeverg')

    run(15, 299, 10, 'g534b5ybredfby65ku6')
    run(16, 299, 10, 'dascsdwg4rtwevscvg4')
    run(17, 300, 10, '54gvedfvrth34t')
    run(18, 300, 10, 'he3t54fvdsav4wer')
    run(19, 300, 10, 'g43ercdcwsht345rfsfd')
    run(20, 300, 10, 'g2e3rwg354gf43wfr')