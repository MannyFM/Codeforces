
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
#define fn "next"

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

void split(pitem t, pitem &l, pitem & r, int key)
{
	if (!t)
	{
		l = r = 0;
		return;
	}
	if (key <= t -> x)
		split(t -> l, l, t -> l, key), r = t;
	else
		split(t -> r, t -> r, r, key), l = t;
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

bool find(pitem t, int x)
{
	if (!t)
		return 0;
	if (t -> x == x)
		return 1;
	return find(x < t -> x ? t -> l : t -> r, x);
}

void insert(pitem &t, int x)
{
	if (find(t, x))
		return;
	pitem t1, t2, it = new item(x);
	split(t, t1, t2, x);
	merge(t, t1, it);
	merge(t, t, t2);
}

void erase(pitem & t, int x)
{
	if (!t)
		return;
	if (t -> x == x)
	{
		merge(t, t -> l, t -> r);
		return;
	}
	erase(x < t -> x ? t -> l : t -> r, x);
	upd(t);
}

int get(pitem t, int x)
{
	if (!t)
		return inf;
	if (t -> x == x)
		return t -> x;
	return min(t -> x > x ? t -> x : inf, get(x < t -> x ? t -> l : t -> r, x));
}

void out(pitem t, int lvl = 0)
{
	if (!t)
		return;
	for (int i = 0; i < lvl; i++)
		printf(" ");
	printf("%d(%d)\n", t -> x, t -> y);
	out(t -> l, lvl + 1);
	out(t -> r, lvl + 1);
}
pitem root;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	int last = 0;
	for (int i = 1; i <= n; i++)
	{
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		if (c == '+')
		{
			insert(root, (last + x) % int(1e9));
			last = 0;
		}
		else
		{
			last = get(root, x);
			if (last >= inf)
				last = -1;
			printf("%d\n", last);
		}
//		out(root);
//		puts("");
	}
}

