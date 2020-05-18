from sys import stdin
from math import sqrt, floor, ceil

fi = open("encryption.in", 'r')
s = fi.readline()
n = len(s) - int(s[-1] == '\n')

l, r = int(floor(sqrt(n))), int(ceil(sqrt(n)))
w, h, area = n, n, (n+10)**2
for i in range(l,r+1):
	for j in range(l,r+1):
		x = i*j
		if x >= n and (x < area or (x == area and i < h)):
			w, h = j, i
			area = x

res = [[' ' for x in range(w)] for y in range(h)]
pos = 0
for i in range(h):
	for j in range(w):
		if pos < n and s[pos] != '\n':
			res[i][j] = s[pos]
			pos += 1

for j in range(w):
	s = ''
	for i in range(h):
		if res[i][j] != ' ':
			s += res[i][j]
	print s,