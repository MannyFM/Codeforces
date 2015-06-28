
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 123)
#define ll long long
#define inf (ll)(1e18 + 123)

struct item
{
	ll sum;
	ll add;
	int l, r;
	item() {};
	item(int l, int r) : sum(0), add(0), l(l), r(r) {};
};

int m, n;
item t[4 * maxn];

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

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item(tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = item(tl, tr);
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (l > r)
		return;
	if (tl == l && tr == r)
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

ll get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
	{
		return t[v].sum;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, min(r, tm))
		+ get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);

}

int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	scanf("%d%d", &n, &m);
	build(1, 0, n - 1);
	while(m--)
	{
		char c;
		cin >> c;
		if (c == 'A')
		{
			int l, r;
			ll x;
			cin >> l >> r >> x;
			update(1, 0, n - 1, l - 1, r - 1, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << get(1, 0, n - 1, l - 1, r - 1) << '\n';
		}
	}
}