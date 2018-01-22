def f(k):
    return (2 ** k - 1) * (2 ** (k - 1))

def solve(n):
    last = 1
    k = 1
    x = f(k)
    while (x <= n):
        if (n % x == 0):
            last = x
        k += 1
        x = f(k)
    return last

n = int(raw_input())
print solve(n)
