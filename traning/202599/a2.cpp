
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "floor4"
#define F first
#define S second

pii t[4 * maxn];

pii com(pii a, pii b)
{
	if (a.F > b.F)
		return a;
	if (a.F < b.F)
		return b;
	a.S = min(a.S, b.S);
	return a;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = mp(1, tl);
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
		return mp (-inf, inf);
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return com(get(v + v, tl, tm, l, min(r, tm)),
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos)
{
	if (tl == tr)
	{
		 t[v].F ^= 1;
		 return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(v + v, tl, tm, pos);
	else
		update(v + v + 1, tm + 1, tr, pos);
	t[v] = com(t[v + v], t[v + v + 1]);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int n = int(2e5 + 2);
	build(1, 1, n);
	int m, j;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &j);
		if (j < 0)
		{
			update(1, 1, n, -j);
		}
		else
		{
			int pos = get(1, 1, n, j, n).S;
			printf("%d\n", pos);
			update(1, 1, n, pos);
		}
	}
}
