
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

struct item
{
	ll k2, k, val;
	item * l, * r;
	item()
	{
		k2 = k = val = 0;
		l = r = 0;
	}
	item(int x)
	{
		k2 = 0;
		k = 0;
		val = x;
		l = r = 0;
	}
};

typedef item * pitem;

int n, a[maxn];

void recalc(pitem t, int tl, int tr)
{
	if (!t)
		assert(1 != 1);
	if (tl == tr)
		return;
	t -> k2 = t -> l -> k2 + t -> r -> k2;
	t -> k = t -> l -> k + t -> r -> k;
}

pitem build(int tl, int tr)
{
	if (tl == tr)
		return new item(tl);
	int tm = (tl + tr) >> 1;
	pitem t = new item();
	t -> l = build(tl, tm);
	t -> r = build(tm + 1, tr);
	recalc(t, tl, tr);
	return t;
}

pitem upd(pitem v, int tl, int tr, int pos)
{
	if (tl == tr)
	{
		pitem t = new item();
		t -> k2 = v -> k2 + 2 * v -> k * v -> val + v -> val;
		t -> k = v -> k + 1;
		t -> val = v -> val;
		return t;
	}
	int tm = (tl + tr) >> 1;
	pitem t = new item();
	if (pos <= tm)
	{
		t -> l = upd(v -> l, tl, tm, pos);
		t -> r = v -> r;
	}
	else
	{
		t -> l = v -> l;
		t -> r = upd(v -> r, tm + 1, tr, pos);
	}
	recalc(t, tl, tr);
	return t;
}

void walk(pitem t, int tl, int tr, int lvl = 0)
{
	for (int i = 0; i < lvl; i++)
		printf(" ");
	printf("v:" I64 " k:" I64 " k2:" I64 " [%d %d]\n", t -> val, t -> k, t -> k2, tl, tr);
	if (tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	walk(t -> l, tl, tm, lvl + 1);
	walk(t -> r, tm + 1, tr, lvl + 1);
}

pitem root[maxn];

ll calc(int l, int r)
{
	return (r - l + 1) * 1ll;
}

int main()
{
	int mx = 0;
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), mx = max(mx, a[i]);
	root[0] = build(1, mx);
	walk(root[0], 1, mx);
	puts("");
	for (int i = 1; i <= n; i++)
	{
		root[i] = upd(root[i - 1], 1, mx, a[i]);
		printf("%d:\n", i);
		walk(root[i], 1, mx);
		puts("");
	}
}
