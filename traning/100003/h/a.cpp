
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;

int const maxn = int(1e5 + 12);
int const maxb = int(2e5 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "shelves"
#define NO {puts("-1"); exit(0);}

struct seg
{
	ll F, S;
	int id, which;
};

struct item
{
	ll val;
	int pos;
	seg s;
	item() : val(0), pos(0) {};
};

item t[4 * maxb];

item operator + (item a, item b)
{
	return a.val > b.val ? a : b;
}

item get(int v, int tl, int tr, int l, int r)
{
	if (tr < l || r < tl)
		return item();
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r) +
		get(v + v + 1, tm + 1, tr, l, r);
}

void upd(int v, int tl, int tr, int pos, int x, seg s)
{
	if (tl == tr)
	{
		t[v].s = s;
		t[v].val = x;
		t[v].pos = tl;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x, s);
	else
		upd(v + v + 1, tm + 1, tr, pos, x, s);
	t[v] = t[v + v] + t[v + v + 1];
}

vector <seg> v;

bool cmp(seg a, seg b)
{
	if (a.S == b.S)
		return a.F < b.F;
	return a.S < b.S;
}

int n, m;
ll a[maxn], b[maxn], A[maxn], B[maxn], pre[maxn];
map <ll, ll> compres, was;
set <ll> all;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(I64, a + i);
		A[i] = A[i - 1] + a[i];
		v.pb({A[i - 1] + 1, A[i], i, 1});
	}
	for (int i = 1; i <= m; i++)
	{
		scanf(I64, b + i);
		B[i] = B[i - 1] + b[i];
		v.pb({B[i - 1] + 1, B[i], i, 0});
	}
	for (seg x: v)
		printf(I64 " " I64 "\n", x.F, x.S);
	for (seg x : v)
	{
		all.insert(x.F);
		all.insert(x.S);
	}
	sort(v.begin(), v.end(), cmp);
	for (seg x: v)
		printf(I64 " " I64 "\n", x.F, x.S);
	for (ll x : all)
	{
		compres[x] = compres.size();
		was[compres[x]] = x;
	}
	for (int i = 0; i < int(v.size()); i++)
	{
		v[i].F = compres[v[i].F];
		v[i].S = compres[v[i].S];
	}
	for (seg x: v)
		printf(I64 " " I64 "\n", x.F, x.S);
	int N = all.size() + 1;
	int ans = 0, pos = 0;
	for (int i = 0; i < int(v.size()); i++)
	{
		item g = get(1, 1, N, 0, v[i].F - 1);
		item cur = get(1, 1, N, v[i].S, v[i].S);
		printf(I64 " " I64 "\n[%d " I64 "] " I64 "\n", v[i].F, v[i].S, 0, v[i].F - 1, g.val);
		printf("[" I64 " " I64 "] " I64 "\n", v[i].S, v[i].S, cur.val);
		if (g.val + 1 > cur.val)
		{
			printf("dp[" I64 "]=" I64 "  %d <- %d\n", v[i].S, g.val + 1, g.s.id, g.pos);
			upd(1, 1, N, v[i].S, g.val + 1, v[i]);
			pre[(int)v[i].S] = g.pos;
			if (g.val + 1 > ans)
			{
				pos = v[i].S;
				ans = g.val + 1;
			}
		}
	}
	vector <seg> a, b;
	while (pos > 0)
	{
		item g = get(1, 1, n, pos, pos);
		printf("%d: (" I64 " " I64 ") %d\n", pos, g.s.F, g.s.S, g.pos);
		if (g.s.which)
			a.pb(g.s);
		else
			b.pb(g.s);
		pos = pre[pos];
	}
	printf("%d %d\n", a.size(), b.size());
	for (auto x : a)
		printf("%d ", x.id);
	puts("");
	for (auto x : b)
		printf("%d ", x.id);
}
