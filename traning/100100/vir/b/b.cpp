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
#define fn "tree"

struct item
{
	int x, y, sz, id;
	item * l, *r, * pr;
	item()
	{
		id = x = y = sz = 0;
		l = r = pr = 0;
	}
	item(int x, int y, int id) : x(x), y(y), id(id)
	{
		sz = 1;
		l = r = pr = 0;
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
	if (t -> l)
		t -> l -> pr = t;
	if (t -> r)
		t -> r -> pr = t;
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
	if (l -> y < r -> y)
		merge(l -> r, l -> r, r), t = l;
	else
		merge(r -> l, l, r -> l), t = r;
	upd(t);
}

int id(pitem t)
{
	return t ? t -> id : 0;
}

void out(pitem t, int lvl = 0)
{
	if (!t)
		return;
	for (int i = 0; i < lvl; i++)
		printf(" ");
	printf("x:%d y:%d id:%d l:%d r:%d\n", t -> x, t -> y, t -> id, id(t -> l), id(t -> r));
	out(t -> l, lvl + 1);
	out(t -> r, lvl + 1);
}

pitem root, t[maxn];
int n;

bool cmp(pitem a, pitem b)
{
	if (!a || !b)
		return a && !b;
	return a -> id < b -> id;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		t[i] = new item(x, y, i);
	}
	random_shuffle(t + 1, t + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		pitem t1, t2;
		split(root, t1, t2, t[i] -> x);
		merge(root, t1, t[i]);
		merge(root, root, t2);
	}
	puts("YES");
	sort(t + 1, t + 1 + n, cmp);
	//out(root);
	for (int i = 1; i <= n; i++)
		printf("%d %d %d\n", id(t[i] -> pr), id(t[i] -> l), id(t[i] -> r));
}
