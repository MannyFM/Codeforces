
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
#define F first
#define S second

ll t[maxn * 4];
int n;
ll a[maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

void update(int v, int tl, int tr, int pos, ll x)
{
	if (tl == tr)
	{
		t[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(v + v, tl, tm, pos, x);
	else
		update(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

ll get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0ll;
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, min(r, tm)) + 
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
}

char q;
int i, j;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int k;
	scanf("%d%d", &n, &k);
	build(1, 1, n);
	while(k--)
	{
		scanf("\n%c%d%d", &q, &i, &j);
		if (q == 'A')
		{
			update(1, 1, n, i, j + 0ll);
		}
		if (q == 'Q')
		{
			printf("%I64d\n", get(1, 1, n, i, j));
		}
	}
}