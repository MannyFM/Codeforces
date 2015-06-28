
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 123)
#define ll long long
#define inf (ll)(1e18 + 123)
#define pii pair <ll, ll>
#define f first
#define s second
#define mp make_pair

int m, l, r, n;
ll a[maxn];
pii t[4 * maxn];

pii com(pii a, pii b)
{
	pii c;
	c.f = min(a.f, b.f);
	c.s = max(a.s, b.s);
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

void update(int v, int tl, int tr, int pos, ll x)
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
	freopen("rvq.in", "r", stdin);
	freopen("rvq.out", "w", stdout);
	n = (int)(1e5 + 12);
	for (int i = 1; i <= n; i++)
		a[i - 1] = (i * 1ll * i) % 12345 + (((i * 1ll * i) % 23456) * i) % 23456;
	build(1, 0, n - 1);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d", &l, &r);
		pii ans;
		if (l > 0)
		{
			ans = get(1, 0, n - 1, l - 1, r - 1);
			printf("%I64d\n", ans.s - ans.f);
		}
		else
		{
			l = -l;
			update(1, 0, n - 1, l - 1, (ll) (r));
		}
	}
}