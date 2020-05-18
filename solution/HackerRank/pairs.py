from sys import stdin

c = {}

fi = open("pairs.in", 'r')
n, k = (int(x) for x in fi.readline().split())
for x in fi.readline().split():
	v = int(x)
	c[v] = c.get(v, 0) + 1

print sum((c[x]*c.get(x-k, 0)) for x in c)
