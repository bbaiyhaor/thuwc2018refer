ret = [["测试点","$K$","分值"]]
for datum in prob['data']:
    args = datum['args']
    row = [
        ','.join(map(str, datum['cases'])),
        "$\\le %s$" % tools.hn(args[0]),
        "$%s$" % tools.hn(datum['score'])
    ]
    ret.append(row)
common.log.debug(u'输出调试信息')
return merge_ver(ret)
