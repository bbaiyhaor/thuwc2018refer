ret = [["数据编号", "$n$", "$m$"]]

for i in range(20):
	if i < 2:
		ret.append([str(i + 1), "$1 \\leq n \\leq %s$" % tools.hn(10), "$m = %s$" % tools.hn(3 + i)])
	elif i < 8:
		ret.append([str(i + 1), "$1 \\leq n \\leq %s$, $n$是质数" % tools.hn(10 ** 5), "$m = %s$" % tools.hn(i)])
	elif i < 14:
		ret.append([str(i + 1), "$1 \\leq n \\leq %s$, $n$是质数" % tools.hn(10 ** 9), "$m = %s$" % tools.hn(i - 6)])
	elif i < 19:
		ret.append([str(i + 1), "$1 \\leq n \\leq %s$" % tools.hn(10 ** 9), "$m = %s$" % tools.hn(i - 12)])
	else:
		ret.append([str(i + 1), "$n = %s$" % tools.hn(635643090), "$m = %s$" % tools.hn(i - 12)])
common.log.debug(u'输出调试信息')
return merge_ver(ret)

