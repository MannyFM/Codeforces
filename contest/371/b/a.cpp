
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, m;
int Q[maxn], qh, qt;

map <int, int> bfs(int x)
{
	map <int, int> d;
	d[x] = 0;
	qh = qt = 0;
	Q[qt++] = x;
	while (qh < qt)
	{
		int v = Q[qh++];
		if (v % 5 == 0 && !d.count(v / 5))
		{
			d[v / 5] = d[v] + 1;
			Q[qt++] = v / 5;
		}
		if (v % 3 == 0 && !d.count(v / 3))
		{
			d[v / 3] = d[v] + 1;
			Q[qt++] = v / 3;
		}
		if (v % 2 == 0 && !d.count(v / 2))
		{
			d[v / 2] = d[v] + 1;
			Q[qt++] = v / 2;
		}
	}
	return d;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	auto d1 = bfs(n), d2 = bfs(m);
	int ans = inf;
	for (pii x : d1)
		if (d2.count(x.F))
			umin(ans, x.S + d2[x.F]);
	if (ans >= inf)
		ans = -1;
	printf("%d", ans);
}

