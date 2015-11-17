
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
#define fn "sum"

struct item
{
	int x, y, sz;
	ll sum = 0ll;
	item * l, * r;
	item() {y = sz = 0; l = r = 0;};
	item(int x) : x(x), y((rand() << 16) + rand()), sz(1), l(0), r(0) {}; 
};

typedef item * pitem;

int sz(pitem t)
{
	return t ? t -> sz : 0;
}

ll sum(pitem t)
{
	return t ? t -> sum : 0ll;
}

void upd(pitem t)
{
	if (!t)
		return;
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
	t -> sum = t -> x + sum(t -> l) + sum(t -> r);
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

void split(pitem t, pitem & l, pitem & r, int key)
{
	if (!t)
	{
		l = r = t;
		return;
	}
	if (key <= t -> x)
		split(t -> l, l, t -> l, key), r = t;
	else
		split(t -> r, t -> r, r, key), l = t;
	upd(t);
}

pitem root;

ll sum(pitem t, int l, int r)
{
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r + 1);
	ll ans = sum(t2);
	merge(t, t1, t2);
	merge(t, t, t3);
	return ans;
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

int n;
ll last;
char l;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char c;
		int x, y;
		scanf(" %c%d", &c, &x);
		if (c == '?')
		{
			scanf("%d", &y);
			last = sum(root, x, y);
			printf(I64 "\n", last);
		}
		else
		{
			if (l == '?')
				x = (x + last) % int(1e9);
			insert(root, x);
		}
		l = c;
	}
}
