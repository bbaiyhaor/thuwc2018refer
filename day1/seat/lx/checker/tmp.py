import os

pro = 'std'
his = 'his'
tmp = 'tmp.out'

os.system("g++-6 %s -o %s -O2 -Wall" % (pro + '.cpp', pro))
os.system("g++-6 %s -o %s -O2 -Wall" % (his + '.cpp', his))

for i in range(1, 21) : 
	fin = str(i) + '.in'
	fans = str(i) + '.ans'
	print "Test case %d , running" % i
	print "Hungarian running..."
	os.system("time ./%s <%s >%s" % (pro, fin, tmp))
	print "std running..."
	os.system("time ./%s <%s >%s" % (his, fin, fans))
	if os.system("diff %s %s" % (fans, tmp)) : 
		print "Wrong Answer"
	else : 
		print "Accepted"
	os.system("rm %s" % tmp)
	print "case %d finished" % i

os.system("rm %s" % pro)
os.system("rm %s" % his)
