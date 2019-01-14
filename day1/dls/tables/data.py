ret = [["测试点","$R_i$","$T$","$\\sum_{i=1}^T R_i-L_i+1$","特殊约束"]]
for datum in prob['data']:
    args = datum['args']
    row = [
        ','.join(map(str, datum['cases'])),
        "$\\le %s$" % tools.hn(args[0]),
        "$\\le %s$" % args[1],
        "$\\le %s$" % tools.hn(args[2]),
        "无特殊约束" if args[3]==0 else\
        "$R_i-L_i\\ge %s$" % tools.hn(999990) if args[3]==1 else\
        "$R_i-L_i\\le 22$" if args[3]==2 else\
        "保证答案不超过$%s$" % tools.hn(args[4])
    ]
    ret.append(row)
common.log.debug(u'输出调试信息')
return merge_ver(ret)
