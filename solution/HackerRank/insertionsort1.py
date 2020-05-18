def print_arr(ar):
	print repr(ar).replace(",", "").replace("[", "").replace("]", "")

def insertionSort(ar):
	n = len(ar)
	for i in range(1,n):
		j, v = i-1, ar[i]
		while j >= 0 and ar[j] > v:
			ar[j+1] = ar[j]
			j -= 1
		ar[j+1] = v
		print_arr(ar)


insertionSort([1, -1])
insertionSort([1, 4, 3, 5, 6, 2])