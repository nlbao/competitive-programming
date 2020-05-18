from sys import stdin

MAX_D = 100005
MAX_F = 4*MAX_D

g = [0]*MAX_F
f = [0]*MAX_F


def init(k, l, r):
	if l > r:
		return
	if l == r:
		f[k] = -l
		return
	mid = (l+r)>>1
	left = k<<1
	right = left+1
	init(left, l, mid)
	init(right, mid+1, r)
	f[k] = max(f[left] + g[left], f[right] + g[right])

def update(k, l, r, pos, value):
	if l > r or r < pos:
		return
	if l >= pos:
		g[k] += value
		return
	mid = (l+r)>>1
	left = k<<1
	right = left+1
	update(left, l, mid, pos, value)
	update(right, mid+1, r, pos, value)
	f[k] = max(f[left] + g[left], f[right] + g[right])


init(1, 1, MAX_D)

fi = open("task-scheduling.in", 'r')
n = int(fi.readline())
for i in range(n):
	v = [int(x) for x in fi.readline().split()]
	update(1, 1, MAX_D, v[0], v[1])
 	print max(0,  f[1]+g[1])