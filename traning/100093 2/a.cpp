	
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
#define fn "stupid_rmq"
#define f first
#define s second
#define LOCAL

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

int t[4 * maxn], d[4 * maxn];
int n, a[maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		d[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
	d[v] = max(d[v + v], d[v + v + 1]);
}

pii com(pii a, pii b)
{
	pii c;
	c.f = min(a.f, b.f);
	c.s = max(a.s, b.s);
	return c;
}

pii get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return mp(inf, -inf);
	if (tl == l && tr == r)
		return mp(t[v], d[v]);
	int tm = (tl + tr) >> 1;
	return com(get(v + v, tl, tm, l, min(r, tm)), 
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr)
	{
		t[v] = x;
		d[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(v + v, tl, tm, pos, x);
	else
		update(v + v + 1, tm + 1, tr, pos, x);
	t[v] = min(t[v + v], t[v + v + 1]);
	d[v] = max(d[v + v], d[v + v + 1]);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = maxn;
	for (int i = 1; i <= n; i++)
		a[i] = (i * 1ll * i) % 12345 + (i * 1ll * i * i) % 23456;
	build(1, 1, n);
	int m, l, r;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &l, &r);
		if (l > 0)
		{
			pii ans = get(1, 1, n, l, r);
			printf("%d\n", abs(ans.s - ans.f));
		}
		else
		{
			update(1, 1, n, -l, r);
		}
	}
}