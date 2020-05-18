from sys import stdin

def check():
	global n, k, a, b
	a.sort()
	b.sort(reverse=True)
	for i in range(n):
		if a[i]+b[i] < k:
			return "NO"
	return "YES"

fi = open("two-arrays.in")
nTest = int(fi.readline())
for test_id in range(nTest):
	n, k = [int(x) for x in fi.readline().split()]
	a = [int(x) for x in fi.readline().split()]
	b = [int(x) for x in fi.readline().split()]
	print check()