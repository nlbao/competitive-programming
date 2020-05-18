from sys import stdin
from random import randrange

a = []
b = []

def check():
	global n, a, b
	c = 0
	for i in range(n):
		if abs(a[i]-b[i]) > 1:
			c += 1
	return str(c%2+1)

fi = open("vertical-rooks.in")
nTest = int(fi.readline())
for test_id in range(nTest):
	n = int(fi.readline())
	for i in range(n):
		a.append(int(fi.readline()))
	for i in range(n):
		b.append(int(fi.readline()))
	# print a
	# print b
	print "player-" + check()
	a[:] = []
	b[:] = []