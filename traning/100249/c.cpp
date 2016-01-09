
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "rmq"
#define F first
#define S second
#define YES {puts("consistent");}
#define NO {puts("inconsistent"); return 0;}

const ll inf = (1ll << 31) + 10;

struct item
{
	ll x, fl;
	item() : x(inf), fl(-inf) {};
};

vector <item> t(4 * maxn, item());

void push(int v, int tl, int tr)
{
	if (t[v].fl == -inf)
		return;
	if (tl != tr)
	{
		t[v + v].fl = t[v].fl;
		t[v + v + 1].fl = t[v].fl;
	}
	t[v].x = t[v].fl;
	t[v].fl = -inf;
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (l > r)
		return;
	push(v, tl, tr);
	if (tl == l && tr == r)
	{
		t[v].fl = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(tm, r), x);
	update(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
	push(v + v, tl, tm);
	push(v + v + 1, tm + 1, tr);
	t[v].x = min(t[v + v].x, t[v + v + 1].x);
}

ll get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return inf;
	push(v, tl, tr);
	if (tl == l && tr == r)
		return t[v].x;
	int tm = (tl + tr) >> 1;
	return min(get(v + v, tl, tm, l, min(tm, r)), 
		get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int n, m;
pair <pii, int> a[maxn];

bool cmp(pair <pii, int> a, pair <pii, int> b)
{
	return (a.S < b.S);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a[i].F.F, &a[i].F.S, &a[i].S);
	}
	sort(a + 1, a + m + 1, cmp);
	
	
	for (int i = 1; i <= m; i++)
		update(1, 1, n, a[i].F.F, a[i].F.S, a[i].S);
	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", get(1, 1, n, i, i));
	puts("");
	*/
	for (int i = 1; i <= m; i++)
	{
		int G = get(1, 1, n, a[i].F.F, a[i].F.S);
		//printf("%d %d %d %d\n", a[i].F.F, a[i].F.S, G, a[i].S);
		if (G != a[i].S)
			NO;
	}
	YES;
	for (int i = 1; i <= n; i++)
		printf("%d ", get(1, 1, n, i, i));
}
