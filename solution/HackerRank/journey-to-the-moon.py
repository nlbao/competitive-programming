import sys
from sys import stdin
from collections import defaultdict


MAX_N = 100005
MAX_M = 1000006

sys.setrecursionlimit(MAX_N)

e = defaultdict(list)


def dfs(u):
	visited[u] = True
	c = 1
	for v in e[u]:
		if not visited[v]:
			c += dfs(v)
	return c


fi = open("journey-to-the-moon.in")
n, m = [int(x) for x in fi.readline().split()]
for i in range(m):
	edge = [int(x) for x in fi.readline().split()]
	for i in range(2):
		e[edge[i]].append(edge[i^1])


visited = [False]*n
res, s = 0, 0
for i in range(n):
	if not visited[i]:
		x = dfs(i)
		res += s*x
		s += x
print res