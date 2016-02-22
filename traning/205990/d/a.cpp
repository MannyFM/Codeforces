
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
	int v, a;
	item * l, * r;
	item ()
	{
		v = 1;
		a = -1;
		l = r = 0;
	}
};

typedef item * pitem;

void push(pitem t, int tl, int tr)
{
	if (!t || t -> a == -1 || tl == tr)
		return;
	if (t -> l && umax(t -> l -> v, t -> a))
		t -> l -> a = t -> a;
	if (t -> r && umax(t -> r -> v, t -> a))
		t -> r -> a = t -> a;
	t -> a = -1;
}

void upd(pitem v, int tl, int tr, int l, int r, int x)
{
	assert(v);
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		if (umax(v -> v, x))
		{
			v -> a = x;
			//printf("%d(%d) [%d %d] (%d %d) = %d\n", v -> v, v -> a, tl, tr, l, r, x);
		}
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (!v -> l)
	{
		v -> l = new item();
		v -> l -> v = v -> v;
	}
	upd(v -> l, tl, tm, l, r, x);
	if (!v -> r)
	{
		v -> r = new item();
		v -> r -> v = v -> v;
	}
	upd(v -> r, tm + 1, tr, l, r, x);
}

int get(pitem v, int tl, int tr, int pos)
{
	push(v, tl, tr);
	if (!v)
		return 1;
//	printf("%d(%d) [%d %d] %d\n", v -> v, v -> a, tl, tr, pos);
	if (tl == tr)
		return v -> v;
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
	{
		if (!v -> l)
			return v -> v;
		return get(v -> l, tl, tm, pos);
	}
	else
	{
		if (!v -> r)
			return v -> v;
		return get(v -> r, tm + 1, tr, pos);
	}
}

pitem hor, ver;
int n, q;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	hor = new item();
	ver = new item();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		if (c == 'L')
		{
			int ans = get(ver, 1, n, y);
			upd(ver, 1, n, y, y, x + 1);
			upd(hor, 1, n, ans, x, y + 1);
			printf("%d\n", x - ans + 1);
		}
		else
		{
			int ans = get(hor, 1, n, x);
			upd(hor, 1, n, x, x, y + 1);
			upd(ver, 1, n, ans, y, x + 1);
			printf("%d\n", y - ans + 1);
		}
	}
}

