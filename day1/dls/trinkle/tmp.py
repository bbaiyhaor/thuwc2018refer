import os

pro = 'std'
tmp = 'tmp.out'

os.system("g++ %s -o %s -O2 -Wall" % (pro + '.cpp', pro))

for i in range(1, 21) : 
	fin = '../data/'+str(i) + '.in'
	fans = '../data/'+str(i) + '.ans'
	print "--------------- Test case %d , running... --------------- " % i
	os.system("time ./%s <%s >%s" % (pro, fin, tmp))
	if os.system("diff %s %s" % (tmp, fans)) :
		print "Wrong Answer"
	else :
		print "Accepted"
	os.system("rm %s" % tmp)
	print "--------------- case %d finished... --------------- " % i

os.system("rm %s" % pro)
