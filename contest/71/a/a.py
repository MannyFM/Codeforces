n = int(raw_input())
for i in xrange(n):
    s = raw_input()
    ans = ""
    if (len(s) > 10):
        ans = s[0] + str(len(s) - 2) + s[-1]
    else:
        ans = s
    print ans
