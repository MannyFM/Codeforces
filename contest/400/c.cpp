
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

int p, n, m;
int x[maxn], y[maxn];

void twist(int i)
{
	int X = n - y[i] + 1;
	int Y = x[i];
	x[i] = X;
	y[i] = Y;
	swap(n, m);
}

void mirror(int i)
{
	int X = m - x[i] + 1;
	x[i] = X;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int a, b, c;
	scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &p);
	for (int i = 1; i <= p; i++)
		scanf("%d%d", y + i, x + i);
	a %= 4;
	b %= 2;
	c %= 4;
	c = (c * 3) % 4;
	for (int i = 1; i <= p; i++)
	{
		int nn = n, mm = m;
		for (int t = 0; t < a; t++)
			twist(i);
		if (b)
			mirror(i);
		for (int t = 0; t < c; t++)
			twist(i);
		n = nn, m = mm;
	}
	for (int i = 1; i <= p; i++)
		printf("%d %d\n", y[i], x[i]);
}