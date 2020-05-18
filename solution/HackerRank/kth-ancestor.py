import sys
from sys import stdin
from collections import defaultdict


MAX_N = 100005
LOG_N = 20

sys.setrecursionlimit(MAX_N)

n = 0
e = defaultdict(list)
h = [-1 for x in range(MAX_N)]
p = [[-1 for x in range(LOG_N)] for y in range(MAX_N)]


def add_node(u):
	for i in range(1,LOG_N):
		if h[u] < (1<<i):
			break
		else:
			p[u][i] = p[p[u][i-1]][i-1]


def dfs(u):
	add_node(u)
	for v in e[u]:
		h[v] = h[u] + 1
		p[v][0] = u
		dfs(v)


def enter():
	global n, e, h
	n = int(fi.readline())
	for i in range(MAX_N):
		e[i][:] = []
		h[i] = -1
	for i in range(n):
		u, r = [int(x) for x in fi.readline().split()]
		e[r].append(u)
	h[0] = 0
	dfs(0)


def get_kth_ancestor(u, k):
	if (u < 1) or (h[u] < 1) or (k >= h[u]):
		return 0
	for i in range(LOG_N-1,-1,-1):
		if k >= (1<<i):
			u = p[u][i]
			k -= 1<<i
	return u


def solve():
	nQ = int(fi.readline())
	for q_id in range(nQ):
		query = [int(x) for x in fi.readline().split()]
		if query[0] == 0:
			u, v = query[1], query[2]
			if h[u] > -1:
				h[v] = h[u] + 1
				p[v][0] = u
				add_node(v)
		elif query[0] == 1:
			h[query[1]] = -1
		else:
			print get_kth_ancestor(query[1], query[2])


fi = open("kth-ancestor.in")
nTest = int(fi.readline())
for test_id in range(nTest):
	enter()
	solve()