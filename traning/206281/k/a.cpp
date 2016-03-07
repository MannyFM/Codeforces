
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <ll, ll> pii;

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

int n, m, w;
int a[maxn];

pii operator + (pii a, pii b)
{
	if (a.F == b.F)
		return {a.F, min(a.S, b.S)};
	return a.F < b.F ? a : b;
}

pii t[4 * maxn];
int add[4 * maxn];

void push(int v, int tl, int tr)
{
	if (!add[v] || tl == tr)
		return;
	add[v + v] += add[v];
	add[v + v + 1] += add[v];
	t[v + v].F += add[v];
	t[v + v + 1].F += add[v];
	add[v] = 0;	
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = {a[tl], tl};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

pii get(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return t[0];
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;	
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		add[v] += x;
		t[v].F += x;
		push(v, tl, tr);
		return;
	}	
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	t[v] = t[v + v] + t[v + v + 1];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	t[0] = {inf, inf};
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{

		pii g = get(1, 1, n, 1, n);
		int pos = min(g.S, n - w + 1ll);
//		printf("[%d %d] %d\n", g.F, g.S, pos);
		upd(1, 1, n, pos, pos + w - 1, 1);
	}	
	pii g = get(1, 1, n, 1, n);
	printf(I64, g.F);
}

