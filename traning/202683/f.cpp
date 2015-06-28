
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "rmq"
#define F first
#define S second

struct item
{
	int x, prior;
	int sz, f;
	item * l, * r;
	item () {};
	item (int x, int prior) : x(x), prior(prior), sz(1), f(x), l(0), r(0) {};
};

typedef item * pitem;

int sz(pitem t)
{
	return t ? t -> sz : 0;
}

int f(pitem t)
{
	return t ? t -> f : inf;
}

void upd(pitem t)
{
	if (!t)
		return;
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
	t -> f = min(min(f(t -> l), f(t -> r)), t -> x);
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

void split(pitem t, pitem & l, pitem & r, int key, int add = 0)
{
	if (!t)
	{
		l = r = 0;
		return;
	}
	int cur_key = add + sz(t -> l);
	if (cur_key >= key)
		split(t -> l, l, t -> l, key, add), r = t;
	else
		split(t -> r, t -> r, r, key, add + 1 + sz(t -> l)), l = t;
	upd(t);
}

void insert(pitem & t, pitem it, int key)
{
	pitem t1, t2;
	split(t, t1, t2, key);
	merge(t1, t1, it);
	merge(t, t1, t2);
}

int get(pitem t, int l, int r)
{
	if (l > r || !t)
		return f(0);
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);
	int ans = f(t2);
	merge(t, t1, t2);
	merge(t, t, t3);
	return ans;
}

pitem root;
int n;
char q;
int i, j;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	while (n--)
	{
		scanf("\n%c%d%d", &q, &i, &j);
		if (q == '+')
		{
			pitem it = new item(j, rand() * rand());
			insert(root, it, i);
		}
		if (q == '?')
		{
			printf("%d\n", get(root, i - 1, j - 1));
		}
	}
}
