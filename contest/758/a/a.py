n = int(raw_input())
a = map(int,raw_input().split())
mx = max(a)
ans = 0
for i in a:
    ans += mx - i
print ans
