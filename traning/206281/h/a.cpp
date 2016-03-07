
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
#define fn "rvq"

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

int n, a[maxn];

struct item
{
	pii mn, mx;
	item ()
	{
		mn = {inf, inf};
		mx = {-inf, -inf};
	}
	item (int x, int pos)
	{
		mx = mn = {x, pos};
	}
	item (pii a, pii b)
	{
		mn = a, mx = b;
	}
} t[4 * maxn];

item operator + (const item & a, const item & b)
{
	pii mn, mx;
	if (a.mn.F == b.mn.F)
		mn = {a.mn.F, min(a.mn.S, b.mn.S)};
	else
		mn = a.mn.F < b.mn.F ? a.mn : b.mn;	
	if (a.mx.F == b.mx.F)
		mx = {a.mx.F, min(a.mx.S, b.mx.S)};
	else
		mx = a.mx.F > b.mx.F ? a.mx : b.mx;
	return item(mn, mx);
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item(a[tl], tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

void upd(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr)
	{
		t[v] = item(x, pos);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

item get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return item();
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	n = maxn - 1;
	for (int i = 1; i <= n; i++)
		a[i] = (i * 1ll * i) % 12345 + (i * 1ll * i * i) % 23456;
	build(1, 1, n);	
	int l, r, m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		if (l > 0)
		{
			item g = get(1, 1, n, l, r);
			printf("%d\n", g.mx.F - g.mn.F);
		}
		else
			upd(1, 1, n, -l, r);
	}
}

