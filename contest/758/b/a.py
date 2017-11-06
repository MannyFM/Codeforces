str = raw_input()
clr = "RBYG"
index = [-1, -1, -1, -1]
cnt = [0, 0, 0, 0]
for i in xrange(4):
    index[i] = str.index(clr[i]) % 4
    print index[i]
for i in xrange(len(str)):
    if (str[i] == '!'):
        cnt[i % 4] += 1
for i in xrange(4):
    print cnt[index[i]],
