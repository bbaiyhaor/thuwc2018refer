import os

pro = 'std'
os.system("g++-6 %s -o %s -O2 -Wall" % (pro + '.cpp', pro))

for i in range(1, 21) : 
	fin = str(i) + '.in'
	fans = str(i) + '.ans'
	print "Test case %d , running..." % i
	os.system("time ./%s <%s >%s" % (pro, fin, fans))
	print "finished"

os.system("rm %s" % pro)
