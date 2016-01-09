
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

struct item
{
	int val, prior, sz;
	item * l, * r;
	item()
	{
		val = prior = sz = 0;
		l = r = 0;
	}
	item(int x)
	{
		val = 1;
		prior = (rand() << 16) + rand();
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
	if (key <= t -> val)
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
	if (l -> prior > r -> prior)
		merge(l -> r, l -> r, r), t = l;
	else
		merge(r -> l, l, r -> l), t = r;
	upd(t);
}

void insert(pitem &t, pitem it)
{
	if (!t)
	{
		t = it;
		return;
	}
	if (it -> prior > t -> prior)
		split(t, it -> l, it -> r, it -> val), t = it;
	else
		insert(it -> val < t -> val ? t -> l : t -> r, it);
	upd(t);
}

bool find(pitem t, int x)
{
	if (!t)
		return 0;
	if (t -> val == x)
		return 1;
	if (x < t -> val)
		return find(t -> l, x);
	else
		return find(t -> r, x);
}

void erase(pitem & t, int x)
{
	if (!t)
		return;
	if (t -> val == x)
	{
		merge(t, t -> l, t -> r);
		return;
	}
	if (x < t -> val)
		erase(t -> l, x);
	else
		erase(t -> r, x);
	upd(t);
}

int cnt(pitem t, int l, int r)
{
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r + 1);
	int ans = sz(t2);
	printf("{%d %d} %d %d %d ->%d\n", l, r, sz(t1), sz(t2), sz(t3));
	merge(t, t1, t2);
	merge(t, t, t3);
	return ans;
}

struct ev
{
	int l, r, x;
	bool v, o;
	ev()
	{
		l = r = x  = v = o = 0;
	}
	ev(int l, int r, int x) : l(l), r(r), x(x), v(1), o(0) {};
	ev(int x, int y, bool open, int) : l(y), r(y), x(x), v(0), o(open) {};
};

bool operator < (const ev & a, const ev & b)
{
	if (a.v != b.v)
		return !a.v && b.v;
	if (a.v)
		return a.x < b.x;
	if (a.o != b.o)
		return a.o && !b.o;
	return a.x < b.x;
}

int n;
vector <ev> v;

pitem root;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x, y;
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		if (x == x1)
		{
			if (y > y1)
				swap(y, y1);
			v.pb(ev(y, y1, x));
		}
		else
		{
			if (x > x1)
				swap(x, x1);
			v.pb(ev(x, y, 1, 1));
			v.pb(ev(x1 + 1, y, 0, 1));
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0ll;
	map <int, int> c;
	map <int, int> pos;
	for (ev & e : v)
	{
		if (e.v)
		{
			ans += e.r - e.l + 1 - cnt(root, e.l, e.r);
			printf("!%d!", cnt(root, e.l, e.r));
			continue;
		}
		if (e.o)
		{
			if (!find(root, e.l))
			{
				insert(root, new item(e.l));
				pos[e.l] = e.x;
			}
			else
				c[e.l]++;
		}
		else
		{
			if (c[e.l])
				c[e.l]--;
			else
			{
				erase(root, e.l);
				ans += e.x - pos[e.l] + 1;
				printf("[%d %d]", pos[e.l], e.x);
			}
		}
	}
	printf(I64, ans);
}

