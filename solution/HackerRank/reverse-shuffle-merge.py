from sys import stdin

nC = 26
oo = 10000

def check(a, b, pos):
	global des
	for i in range(nC):
		t = c[pos][i]
		tmax, tmin = max(des[i]-a[i], des[i]-b[i]), min(des[i]-a[i], des[i]-b[i])
		if (t-tmax < 0) or (t-tmax-tmin < 0):
			return False
	return True

def get_c(i, j):
	if i > j:
		return [0]*nC
 	return [(c[i][x]-c[j+1][x]) for x in range(nC)]

def find(first):
	global m, c
	pos = next[0][first]
	if s[0] == first:
		pos = 0
	if pos >= n:
		return [oo]*m

	choose = [first]
	a = [0]*nC
	a[s[pos]] += 1
	b = get_c(0,pos-1)
	if not check(a, b, pos+1):
		return [oo]*m

	cm = 1
	while pos < n and cm < m:
		i = nC-1
		while i >= 0:
			p = next[pos][i]
			if p < n:
				ta = [a[x]+int(x == i) for x in range(nC)]
				tc = get_c(pos+1, p-1)
				tb = [b[x]+tc[x] for x in range(nC)]
				if check(ta, tb, p+1):
					pos = p
					choose.insert(0, s[pos])
					# choose.append(s[pos])
					a, b = list(ta), list(tb)
					cm += 1
					break
			i -= 1
		if i < 0:
			return [oo]*m
	i = 4
	# print check(a, b, pos+1), des[i]-a[i] + des[i]-b[i], c[pos][i]
	if cm < m:
		return [oo]*m
	return choose


fi = open("reverse-shuffle-merge.in")
s = [ord(x)-ord("a") for x in fi.readline()]
n = len(s)
if s[n-1] < 0 or s[n-1] >= nC:
    n -= 1
m = n/2

# f = [[0 for x in range(nC)] for y in range(n)]
c = [[0]*nC]*(n+1)
f = list(c)
g = list(c)
next = [[n]*nC]*(n+1)

c[n-1][s[n-1]] = 1
for i in range(n-2, -1, -1):
	c[i] = list(c[i+1])
	c[i][s[i]] += 1
	next[i] = list(next[i+1])
	next[i][s[i+1]] = i+1
des = [x/2 for x in c[0]]

res = find(s[0])
for x in range(nC-1,-1,-1):
	tmp = find(x)
	if tmp[0] < oo:
		if cmp(tmp, res) == -1:
			res = list(tmp)
	 	# print ''.join([chr(x+ord("a")) for x in tmp])

# print
# print s
# print res
print ''.join([chr(x+ord("a")) for x in res])