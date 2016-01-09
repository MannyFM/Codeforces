
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
#define fn "painter"

struct item
{
	int cnt, pre, suf, sum, add;
	item()
	{
		cnt = pre = suf = sum = 0;
		add = 0;
	}
	item(int)
	{
		cnt = pre = suf = sum = 0;
		add = 1;
	}
	item(int tl, int tr)
	{
		cnt = 1;
		pre = suf = 1;
		sum = tr - tl + 1;
		add = 2;
	}
} t[4 * maxn];

int const shift = 500 * 1000 + 2, n = shift * 2 + 1;

item operator + (item a, item b)
{
	item c = item();
	c.sum = a.sum + b.sum;
	c.cnt = a.cnt + b.cnt;
	if (a.suf && b.pre)
		c.cnt--;
	c.pre = a.pre;
	c.suf = b.suf;
	return c;
}

//1 White
//2 Black

void push(int v, int tl, int tr)
{
	if (!t[v].add || tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	t[v + v].add = t[v].add;
	t[v + v + 1].add = t[v].add;
	if (t[v].add == 1)
	{
		t[v + v] = item(1);
		t[v + v + 1] = item(1);
	}
	else
	{
		t[v + v] = item(tl, tm);
		t[v + v + 1] = item(tm + 1, tr);
	}
	t[v].add = 0;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = item(0);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

void upd(int v, int tl, int tr, int l, int r, int clr)
{
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		if (clr == 1)
			t[v] = item(1);
		else
			t[v] = item(tl, tr);
		push(v, tl, tr);
	//	if (t[v].sum)
	//		printf("%d: [%d %d] sum:%d cnt:%d pre:%d suf:%d add:%d\n", v, tl, tr, t[v].sum, t[v].cnt, t[v].pre, t[v].suf, t[v].add);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, clr);
	upd(v + v + 1, tm + 1, tr, l, r, clr);
	t[v] = t[v + v] + t[v + v + 1];
	//if (t[v].sum)
	//{
	//	printf("%d sum:%d cnt:%d pre:%d suf:%d add:%d + ", v + v, t[v + v].sum, t[v + v].cnt, t[v + v].pre, t[v + v].suf, t[v + v].add);
	//	printf("%d sum:%d cnt:%d pre:%d suf:%d add:%d = ", v + v + 1, t[v + v + 1].sum, t[v + v + 1].cnt, t[v + v + 1].pre, t[v + v + 1].suf, t[v + v + 1].add);
	//	printf("%d [%d %d] sum:%d cnt:%d pre:%d suf:%d add:%d\n", v, tl, tr, t[v].sum, t[v].cnt, t[v].pre, t[v].suf, t[v].add);
	//}
}

item get(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return item();
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

char c;
int l, r, m;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &m);
	build(1, 0, n);
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c%d%d", &c, &l, &r);
		r = l + r - 1;
		//printf("[%d %d]\n", l, r);
		upd(1, 1, n, l + shift, r + shift, 1 + (c == 'B'));
		item g = get(1, 0, n, 0, n);
		printf("%d %d\n", g.cnt, g.sum);
	}
}

