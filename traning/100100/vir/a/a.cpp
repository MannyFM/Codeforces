
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
#define fn "movetofront"

struct item
{
	int x, y, sz;
	item * l, *r;
	item()
	{
		x = y = sz = 0;
		l = r = 0;
	}
	item(int x) : x(x)
	{
		y = (rand() << 16) + rand();
		sz = 1;
		l = r = 0;
	}
};

typedef item * pitem;

int sz(pitem t)
{
	return t ? t -> sz : 0;
}


void upd(pitem t)
{
	if (!t)
		return;
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
}

void split(pitem t, pitem &l, pitem & r, int key, int add = 0)
{
	if (!t)
	{
		l = r = 0;
		return;
	}
	int cur_key = add + sz(t -> l);
	if (key <= cur_key)
		split(t -> l, l, t -> l, key, add), r = t;
	else
		split(t -> r, t -> r, r, key, add + sz(t -> l) + 1), l = t;
	upd(t);
}

void merge(pitem & t, pitem l, pitem r)
{
	if (!l || !r)
	{
		t = l ? l : r;
		return;
	}
	if (l -> y > r -> y)
		merge(l -> r, l -> r, r), t = l;
	else
		merge(r -> l, l, r -> l), t = r;
	upd(t);
}

void out(pitem t, int lvl = 0)
{
	if (!t)
		return;
	out(t -> l, lvl + 1);
	printf("%d ", t -> x);
	out(t -> r, lvl + 1);
}

void shift(pitem &t, int l, int r)
{
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);
	merge(t, t2, t1);
	merge(t, t, t3);
}

pitem root;
int n, m;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		merge(root, root, new item(i));
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		shift(root, l, r);
	}
	out(root);
}

