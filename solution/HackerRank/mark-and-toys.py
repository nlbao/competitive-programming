from sys import stdin

MAX_N = 100005

n = 0
k = 0
a = []

fi = open("mark-and-toys.in")
n, k = [int(x) for x in fi.readline().split()]
for x in fi.readline().split():
	a.append(int(x))

a.sort()
res = 0
for i in range(n):
	k -= a[i]
	if k < 0:
		break
	res += 1
print res