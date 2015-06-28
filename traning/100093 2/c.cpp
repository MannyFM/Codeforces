
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
#define fn "sum"
#define LOCAL
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

struct item
{
	ll x, add;
	item(){};
	item(int x) : x(x) {};
};

item t[4 * maxn];

void push(int v, int tl, int tr)
{
	if (t[v].add == -1)
		return;
	t[v].x += (tr - tl + 1ll) * t[v].add;
	if (tl != tr)
	{
		int tm = (tl + tr) >> 1;
		t[v + v].add = t[v].add;
		t[v + v].x = (tm - tl + 1) * t[v + v].add;
		t[v + v + 1].add = t[v].add;
		t[v + v + 1].x = (tr - tm) * t[v + v + 1].add;
	}
	t[v].add = -1;
}

ll get(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);
	if (l > r)
		return 0ll;
	if (tl == l && tr == r)
		return t[v].x;
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, min(r, tm))
		+ get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void build(int v, int tl, int tr)
{
	push(v, tl, tr);
	if (tl == tr)
	{
		t[v].x = 0;
		t[v].add = -1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v].add = -1;
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	push(v, tl, tr);
	if (l > r)
		return;
	if (tl == l && tr == r)
	{
		t[v].x = (r - l + 1) * x;
		t[v].add = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v].x = t[v + v].x + t[v + v + 1].x;
}

int l, r, x, n, k;
char q;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	build(1, 1, n);
	for (int i = 1; i <= k; i++)
	{
		scanf("\n%c", &q);
		if (q == 'A')
		{
			scanf("%d%d%d", &l, &r, &x);
			update(1, 1, n, l, r, x);
		}
		else
		{
			scanf("%d%d", &l, &r);
			ll ans = get(1, 1, n, l, r);
			printf("%I64d\n", ans);
		}
	}
}