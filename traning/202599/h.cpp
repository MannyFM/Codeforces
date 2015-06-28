
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
#define fn "rvq"
#define F first
#define S second

pii t[maxn * 4];
int n, a[maxn];

pii com(pii a, pii b)
{
	pii c;
	c.F = min(a.F, b.F);
	c.S = max(a.S, b.S);
	return c;
}

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

pii get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return mp(inf, -inf);
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return com(get(v + v, tl, tm, l, min(r, tm)),
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = maxn;
	for (int i = 1; i < n; i++)
		a[i] = int((i * 1ll * i) % 12345 + (i * 1ll * i * i) % 23456);
	/*
	for (int i = 1; i <= 10; i++)
		printf("%d ", a[i]);
	puts("");
	*/
	build(1, 1, n);
	int m, i, j;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &i, &j);
		if (i < 0)
			update(1, 1, n, -i, j);
		else
		{
			pii ans = get(1, 1, n, i, j);
			printf("%d\n", ans.S - ans.F);
		}
	}
}