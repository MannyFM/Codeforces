
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define fn "frog"

pii T[4 * maxn];

struct frog
{
	ll a, b, l;
	int c, i;
	frog() :a(0), b(0), l(0), c(0), i(0) {};
	frog(int x, int y, int i) : a(x), b(x + y), l(y), c(0), i(i) {};
	bool operator < (const frog & p)
	{
		return a < p.a;
	}
} a[maxn];

ll t[4 * maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = a[tl].b;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = max(t[v + v], t[v + v + 1]);
}

void upd(int v, int tl, int tr, int pos, int val)
{
	if (tl == tr)
	{
		t[v] += val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, val);
	else
		upd(v + v + 1, tm + 1, tr, pos, val);
	t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int tl, int tr, ll x)
{
	if (tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	if (t[v + v] >= x)
		return get(v + v, tl, tm, x);
	if (t[v + v + 1] >= x)
		return get(v + v + 1, tm + 1, tr, x);
	return -1;
}

multiset <pll> alive;
int n, m;
int x[maxn], y[maxn], p[maxn], b[maxn];

bool eat(int pos, ll x, ll w)
{
	//printf("#%d(a" I64 ") eat w" I64 "\n", a[pos].i, a[pos].a, w);
	if (a[pos].b < x || a[pos].a > x)
		return 0;
	a[pos].b += w;
	a[pos].l += w;
	a[pos].c++;
	upd(1, 1, n, pos, w);
	return 1;
}

int cnt[maxn];
ll len[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", x + i, y + i);
		a[i] = frog(x[i], y[i], i); 
	}
	sort(a + 1, a + 1 + n);
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", p + i, b + i);
		int pos = get(1, 1, n, p[i]);
		//printf("p%d b%d pos%d\n", p[i], b[i], pos);
		if (pos == -1 || !eat(pos, p[i], b[i]))
		{
			alive.insert(mp(p[i], b[i]));
			continue;
		}
		auto it = alive.lower_bound(mp(a[pos].a, -1));
		while (it != alive.end() && it -> F <= a[pos].b)
		{
			if (!eat(pos, it -> F, it -> S))
				break;
			alive.erase(it);
			it = alive.lower_bound(mp(a[pos].a, -1));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i].i] = a[i].c;
		len[a[i].i] = a[i].l;
	}
	for (int i = 1; i <= n; i++)
		printf("%d " I64 "\n", cnt[i], len[i]);
}

