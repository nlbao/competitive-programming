
n = 100

def tn():
    global n
    n *= 11
    return n

print n
print tn()
print n

print n**4
