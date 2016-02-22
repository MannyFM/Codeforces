
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
	ll val;
	item * l, * r;
	item ()
	{
		val = 0;
		l = r = 0;
	}
};

typedef item * pitem;

ll get(pitem v, ll tl, ll tr, ll l, ll r)
{
	if (!v || l > r || tr < l || r < tl)
		return 0ll;
	if (l <= tl && tr <= r)
		return v -> val;
	ll tm = (tl + tr) >> 1;
	return max(get(v -> l, tl, tm, l, r),
			get(v -> r, tm + 1, tr, l, r));
}

ll VAL(pitem t)
{
	return t ? t -> val : 0ll;
}

void upd(pitem v, ll tl, ll tr, ll pos, ll val)
{
	assert(v);
	if (tl == tr)
	{
		umax(v -> val, val);
		return;
	}
	ll tm = (tl + tr) >> 1;
	if (pos <= tm)
	{
		if (!v -> l)
			v -> l = new item();
		upd(v -> l, tl, tm, pos, val);
	}
	else
	{
		if (!v -> r)
			v -> r = new item();
		upd(v -> r, tm + 1, tr, pos, val);
	}
	v -> val = max(VAL(v -> l), VAL(v -> r));
}

ll N = 10000ll * 10000 * 10000;
pitem t = new item();
int n, h[maxn], r[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", r + i, h + i);
	for (int i = 1; i <= n; i++)
	{
		ll V = h[i] * 1ll * r[i] * r[i];
		ll ans = get(t, 1, N, 1, V - 1);
		upd(t, 1, N, V, ans + V);
	}
	ll ans = get(t, 1, N, 1, N);
//	printf(I64 "\n", ans);
	printf("%.12f\n", ans * pi);

}

