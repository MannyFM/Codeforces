import sys
fn = "sum"
sys.stdin = open(fn + ".in", "r")
sys.stdout = open(fn + ".out", "w")

def check(x):
	cnt = 0
	while (x > 9):
		if (x % 10 != 0):
			return -1
		else:
			x //= 10
			cnt += 1
	if (x != 1):
		return -1
	return cnt

a = int(input())
b = int(input())
c = int(input())

maxn = 10 ** 3 + 4
for X in range(maxn):
	q = X
	C = a * (10 ** q) + b
	e = C // c
	E = check(e)
	if (E != -1 and e * c == C):
		print("YES");
		print(q, 0, E)
		exit(0)
	
	B = c - (10 ** q) * a
	#if (B >= 0):
	w = B // b
	W = check(w)
	if (W != -1 and w * b == B):
		print("YES");
		print(q, W, 0)
	exit(0)
	
	w = X
	C = b * (10 ** w) + a
	e = C // c
	E = check(e)
	if (E != -1 and e * c == C):
		print("YES");
		print(0, w, E)
		exit(0)

print("NO")