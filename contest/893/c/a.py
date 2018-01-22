def dfs(v):
    us[v] = True
    val = C[v]
    for to in G[v]:
        if not us[to]:
            val = min(val, dfs(to))
    return val

n, m = map(int, raw_input().split())
C = map(int, raw_input().split())
G = [[]] * n
us = [False] * n

for i in xrange(m):
    x, y = map(int, raw_input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

ans = 0
for i in xrange(n):
    if not us[i]:
        ans += dfs(i)
print ans
