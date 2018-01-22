def solve(a):
    z = 3
    for i in a:
        if i == z:
            return False
        z = 1 + 2 + 3 - z - i
    return True

n = int(raw_input())
a = map(int, [raw_input() for i in xrange(n)])
print 'YES' if solve(a) else 'NO'
