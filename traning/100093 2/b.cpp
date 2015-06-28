	
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 120)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "rvq"
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

pii com(pii a, pii b)
{
	pii c;
	c.f = min(a.f, b.f);
	c.s = max(a.s, b.s);
	return c;
}

pii t[4 * maxn];
int n, a[maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = mp(a[tl], a[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = com(t[v + v], t[v + v + 1]);
}

pii get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return mp(inf, -inf);
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	pii a = get(v + v, tl, tm, l, min(r, tm));
	pii b = get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
	return com(a, b);
}

void update(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr)
	{
		t[v] = mp(x, x);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(v + v, tl, tm, pos, x);
	else
		update(v + v + 1, tm + 1, tr, pos, x);
	t[v] = com(t[v + v], t[v + v + 1]);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = maxn;
	for (int i = 1; i <= n; i++)
		a[i - 1] = (i * 1ll * i) % 12345 + (i * 1ll * i * i) % 23456;
	/*
	for (int i = 1; i <= 102; i++)
		cerr << a[i] << " ";
	*/
	build(1, 0, n - 1);
	int m, l, r;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &l, &r);
		if (l > 0)
		{
			pii ans = get(1, 0, n - 1, l - 1, r - 1);
			printf("%d\n", ans.s - ans.f);
		}
		else
		{
			l = -l;
			update(1, 0, n - 1, l - 1, r);
		}
	}
}