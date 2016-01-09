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
	int x, y, id;
	item * l, * r, * pr;
	item() : x(0), y(0), id(0), l(0), r(0), pr(0){}
	item(int x, int y, int id) : x(x), y(y), id(id), l(0), r(0), pr(0){}
};

typedef item * pitem;

int id(pitem t)
{
	return t ? t -> id : 0;
}

bool cmp(pitem a, pitem b)
{
	if (!a || !b)
		return a && !b;
	return a -> x == b -> x ? a -> y < b -> y : a -> x < b -> x;
}

int n;
int l[maxn], r[maxn], pr[maxn];
pitem t[maxn], last, root;

void calc(pitem t)
{
	if (!t)
		return;
	int i = id(t);
	l[i] = id(t -> l);
	r[i] = id(t -> r);
	pr[i] = id(t -> pr);
	if (t -> l)
		t -> l -> pr = t;
	calc(t -> l);
	if (t -> r)
		t -> r -> pr = t;
	calc(t -> r);
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
	sort(t + 1, t + 1 + n, cmp);
	last = t[1];
	for (int i = 2; i <= n; i++)
	{
		while (last -> pr && last -> y > t[i] -> y)
			last = last -> pr;
		if (last -> y < t[i] -> y)
		{
			t[i] -> l = last -> r;
			if (last -> r)
				last -> r -> pr = t[i];
			last -> r = t[i];
			t[i] -> pr = last;
		}
		else
		{
			t[i] -> l = last;
			last -> pr = t[i];
		}
		last = t[i];
	}
	root = last;
	while (root -> pr)
		root = root -> pr;
	calc(root);
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d %d %d\n", pr[i], l[i], r[i]);

}
