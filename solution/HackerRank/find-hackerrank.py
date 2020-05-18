from sys import stdin

pattern = "hackerrank"
m = len(pattern)

fi = open("find-hackerrank.in", 'r')
n = int(fi.readline())
for line in fi:
	n = len(line)
	if n < m:
		print -1
	else:
		start = line[:m]
		end = line[n-1-m:n-1]
		if start == pattern and end == pattern:
			print 0
		elif start == pattern:
			print 1
		elif end == pattern:
			print 2
		else:
			print -1