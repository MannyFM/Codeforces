
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

pii T[4 * maxn];
int a[maxn], add[4 * maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		T[v] = {a[tl], tl};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	T[v] = min(T[v + v], T[v + v + 1]);
}

void push(int v, int tl, int tr)
{
	if (!add[v] || tl == tr)
		return;
	add[v + v] += add[v];
	add[v + v + 1] += add[v];
	T[v + v].F += add[v];
	T[v + v + 1].F += add[v];
	add[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
	if (l > r || tr < l || r < tl)
		return;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		T[v].F += x;
		add[v] += x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	T[v] = min(T[v + v], T[v + v + 1]);
}

pii get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return {inf, inf};
	push(v, tl, tr);
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return min(get(v + v, tl, tm, l, r),
			get(v + v + 1, tm + 1, tr, l, r));
}

int n, m, w;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		pii g = get(1, 1, n, 1, n);
		int pos = g.S;
		if (pos + w - 1 > n)
			pos = n - w + 1;
		if (pos < 1)
			pos = 1;
//		printf("+[%d %d] ", pos, pos + w - 1);
		upd(1, 1, n, pos, pos + w - 1, 1);
	}
	pii g = get(1, 1, n, 1, n);
	printf("%d", g.F);
}

