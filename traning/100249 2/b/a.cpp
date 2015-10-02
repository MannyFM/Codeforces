
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

struct item
{
	ll mx, mn, add;
	item()
	{
		mx = mn = add = 0ll;
	}
	item(ll x)
	{
		mx = mn = add = x;
	}
};

item cmb(item a, item b)
{
	a.mx = max(a.mx, b.mx);
	a.mn = min(a.mn, b.mn);
	a.add = 0ll;
	return a;
}

int n;
item t[4 * maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item((tl * 1ll * tl) % 12345 + (tl * 1ll * tl * tl) % 23456);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = cmb(t[v + v], t[v + v + 1]);
}

void upd(int v, int tl, int tr, int pos, ll x)
{
	if (tl == tr)
	{
		t[v] = item(x);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	t[v] = cmb(t[v + v], t[v + v + 1]);
}

item sum(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return t[0];
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return cmb(sum(v + v, tl, tm, l, r),
		sum(v + v + 1, tm + 1, tr, l, r));
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = maxn - 12;
	t[0].mx = -linf;
	t[0].mn = linf;
	build(1, 1, n);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > 0)
		{
			item g = sum(1, 1, n, x, y);
			printf(I64 "\n", g.mx - g.mn);
		}
		else
		{
			upd(1, 1, n, -x, y);
		}
	}
}
