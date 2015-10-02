
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define fn "bigwall"

struct item
{
	ll val, add;
	item()
	{
		val = add = 0ll;
	}
	item(ll x)
	{
		val = x;
		add = 0ll;
	}
} T[4 * maxn];

void push(int v, int tl, int tr)
{
	if (!T[v].add || tl == tr)
		return;
	T[v + v].add += T[v].add;
	T[v + v].val += T[v].add;
	T[v + v + 1].add += T[v].add;
	T[v + v + 1].val += T[v].add;
	T[v].add = 0ll;
}

item cmb(item a, item b)
{
	return item(max(a.val, b.val));
}

void upd(int v, int tl, int tr, int l, int r, ll x)
{
	if (l > r || tr < l || r < tl)
		return;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		T[v].add += x;
		T[v].val += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	T[v] = cmb(T[v + v], T[v + v + 1]);
}

item get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return T[0];
	push(v, tl, tr);
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return cmb(get(v + v, tl, tm, l, r),
		get(v + v + 1, tm + 1, tr, l, r));
}

char c[6];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int l, r;
		scanf("%s%d%d", c, &l, &r);
		if (c[0] == 'b')
		{
			int x;
			scanf("%d", &x);
			upd(1, 1, N, l, r, x);
		}
		else
		{
			printf(I64 "\n", get(1, 1, N, l, r).val);
		}
	}
}
