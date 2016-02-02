
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

struct item
{
	int all, open, close;
	item()
	{
		all = open = close = 0;
	}
	item(char x)
	{
		all = open = close = 0;
		if (x == '(')
			open++;
		else
			close++;
	}
	void out(char c = '\n')
	{
		printf("a:%d o:%d c:%d %c", all, open, close, c);
	}
};

item operator + (item a, item b)
{
	a.out('+'), b.out('=');
	item c = item();
	c.all = a.all + b.all + min(a.open, b.close);
	int x = min(a.open, b.close);
	if (x)
		a.open = 0, b.close = 0;
	c.close = a.close + (!a.all ? b.close: 0);
	c.open = b.open + (!b.all ? a.open : 0);
	c.out('+');
	return c;
}

int n;
char s[maxn];
item t[4 * maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item(s[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

item get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return item();
	if (l <= tl && tr <= r)
	{
		printf("[%d %d] a:%d o:%d c:%d\n", tl, tr, t[v].all, t[v].open, t[v].close);
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int m, l, r;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		item g = get(1, 1, n, l, r);
		printf("%d %d %d\n", g.all, g.open, g.close);
		printf("%d\n", g.all);
	}
}

