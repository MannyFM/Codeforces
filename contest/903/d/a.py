mn, mx = 1, 10 ** 9
n = 200 * 1000
step = 1
print mn, mx, step
a = []
for i in xrange(1, n + 1):
    a.append(i)

s = "%d\n" % len(a)
for x in a:
    s += "%d " % x

f = open("input.txt", "w")
f.write(s)
