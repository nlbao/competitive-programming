from sys import stdin

fi = open("flowers.in", 'r')
n, k = [int(x) for x in fi.readline().split()]
a = [int(x) for x in fi.readline().split()]
a.sort(reverse=True)
p, c, res = 0, 1, 0
for x in a:
	res += x*c
	if p == k-1:
		c += 1
	p = (p+1)%k
print res