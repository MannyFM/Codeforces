
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define ll long long

struct item
{
	int x;
	long long sum;
	long long add;
	int l, r;
	item () : x(0), sum(0ll), add(0ll), l(0), r(0) {};
	item (int x, int l, int r) : x(x), sum(0ll), add(0ll), l(l), r(r) {};
};

int n, k;
item t[4 * maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item(0, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = item(0, tl, tr);
}

void push(int v)
{
	if (t[v].add != -1)
	{
		t[v + v].add = t[v].add;
		t[v + v].sum = (t[v + v].r - t[v + v].l + 1ll) * t[v + v].add;
		t[v + v + 1].add = t[v].add;
		t[v + v + 1].sum = (t[v + v + 1].r - t[v + v + 1].l + 1ll) * t[v + v + 1].add;
		t[v].add = -1;
		t[v].sum = t[v + v].sum + t[v + v + 1].sum;
	}
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (l > r)
		return;
	if (l == tl && r == tr)
	{
		t[v].add = x;
		t[v].sum = (t[v].r - t[v].l + 1ll) * x;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v].sum = t[v + v].sum + t[v + v + 1].sum;
}

ll sum(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (tl == l && tr == r)
		return t[v].sum;
	push(v);
	int tm = (tl + tr) >> 1;
	return sum(v + v, tl, tm, l, min(tm, r))
		+ sum(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	scanf("%d%d", &n, &k);
	build(1, 0, n - 1);
	char c;
	while(k--)
	{
		cin >> c;
		if (c == 'A')
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			update(1, 0, n - 1, l - 1, r - 1, x);
		}
		if (c == 'Q')
		{
			
			int l, r;
			scanf("%d%d", &l, &r);
			ll ans = sum(1, 0, n - 1, l - 1, r - 1);
			printf("%I64d\n", ans);
			
		}
	}
}
