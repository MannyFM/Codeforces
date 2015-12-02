
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
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
#define fn "a"

struct item
{
	ll h;
	int len;
	item() : h(0), len(0) {};
	item(int x) : h(x + 1), len(1) {};
	item(ll h, int len) : h(h), len(len) {};
};

int const P = 12, mod = inf;
ll p[maxn], pre[maxn];
char s[maxn];
item t[4 * maxn];
int add[4 * maxn];
int n, m, k;

item operator + (item a, item b)
{
	if (!a.len)
		return b;
	if (!b.len)
		return a;
	item c = item((a.h * p[b.len] + b.h) % mod, a.len + b.len);
	//printf(I64 " %d + " I64 " %d = " I64 " %d\n", a.h, a.len, b.h, b.len, c.h, c.len);
	return c;
}

void push(int v, int tl, int tr)
{
	if (tl == tr || add[v] == -1)
		return;
	int tm = (tl + tr) >> 1;
	add[v + v] = add[v];
	add[v + v + 1] = add[v];
	t[v + v].h = (pre[tm - tl] * add[v]) % mod;
	t[v + v + 1].h = (pre[tr - tm - 1] * add[v]) % mod;
	add[v] = -1;
}

void build(int v, int tl, int tr)
{
	add[v] = -1;
	if (tl == tr)
	{
		t[v] = item(s[tl] - '0');
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

item get(int v, int tl, int tr, int l, int r)
{
	if (tr < l || r < tl || tl > tr || l > r)
		return item();
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		//printf("%d %d %d %d %d  " I64 "\n", v, tl, tr, l, r, t[v].h);
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	item g = get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
	//printf("%d %d %d %d %d  " I64 "\n", v, tl, tr, l, r, g.h);
	return g;
}

void upd(int v, int tl, int tr, int l, int r, ll x)
{
	if (tr < l || r < tl || tl > tr || l > r)
		return;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		//printf(I64 "*" I64 "*" I64 "=" I64 "\n", tr - tl + 1ll, pre[tr - tl], x, (((tr - tl + 1ll) * pre[tr - tl + 1]) % mod * x) % mod);
		t[v].h = ((pre[tr - tl]) % mod * x) % mod;
		add[v] = x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	t[v] = t[v + v] + t[v + v + 1];
}

void walk(int v, int tl, int tr, int lvl = 0)
{
	for (int i = 0; i < lvl; i++)
		putchar(' ');
	printf("%d %d %d " I64 " %d\n", v, tl, tr, t[v].h, t[v].len);
	int tm = (tl + tr) >> 1;
	if (tl != tr)
	{
		walk(v + v, tl, tm, lvl + 1);
		walk(v + v + 1, tm + 1, tr, lvl + 1);
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	p[0] = 1;
	pre[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		p[i] = (p[i - 1] * P) % mod;
		pre[i] = (pre[i - 1] + p[i]) % mod;
	}
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s + 1);
	build(1, 1, n);
	/*
	for (int i = 1; i <= n; i++)
		cout  << i << ":" << pre[i] << " ";
	cout  << '\n';
	
	puts("****");
	for (int i = 1; i <= n; i++)
		printf(I64 " ", get(1, 1, n, i, i).h);
	puts("\n****");
	*/
	m += k;
	for (int i = 1; i <= m; i++)
	{
		int c, l, r, x;
		scanf("%d%d%d%d", &c, &l, &r, &x);
		if (c == 1)
		{
			upd(1, 1, n, l, r, x + 1);
			/*
			puts("****");
			for (int i = 1; i <= n; i++)
				printf(I64 " ", get(1, 1, n, i, i).h);
			puts("\n****");
			*/
		}
		else
		{
			//walk(1, 1, n);
			item L = get(1, 1, n, l, r - x);
			//cout  << '\n';
			item R = get(1, 1, n, l + x, r);
			//cout  << "\n\n";
			//printf(I64 " %d  ?  " I64 " %d\n", L.h, L.len, R.h, R.len);
			puts(L.h == R.h ? "YES" : "NO");
		}
	}
}

