from sys import stdin

MAX_N = 100005
MAX_F = 1000006

def read_int(f):
	return int(f.readline());

def update(i):
	while i < MAX_F:
		f[i] += 1
		i += i & -i

def get(i):
	if i < 1:
		return 0
	return f[i] + get(i - (i & -i))


fi = open("insertion-sort.in", 'r')
nTest = read_int(fi)
for test_id in range(nTest):
	n = read_int(fi)
	a = [int(x) for x in fi.readline().split()]
	f = [0 for x in range(MAX_F)]
	res = 0
	for (i,x) in enumerate(a):
		res += i-get(x)
		update(x)
	print res