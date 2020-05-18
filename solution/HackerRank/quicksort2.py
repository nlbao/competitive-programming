from random import randrange

def quick_sort(a):
	if not a:
		return []
	p = a[0]
	left = quick_sort([x for x in a if x < p])
	right = quick_sort([x for x in a if x > p])
	a = left + [p] + right
	if len(a) > 1:
		for x in a:
			print x,
		print
	return a

def qsort(a):
	if not a:
		return []
	p = a.pop(randrange(len(a)))
	return qsort([x for x in a if x < p]) + [p] + qsort([x for x in a if x > p])


a = [5, 8, 1, 3, 7, 9, 2]
# quick_sort(a)
print a
print qsort(a)
print a

