
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
//#define fn

int n, a[maxn];

ll t[4 * maxn], T[4 * maxn];

void upd(ll * t, int v, int tl, int tr, int pos, ll x)
{
	if (tl == tr)
	{
		t[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(t, v + v, tl, tm, pos, x);
	else
		upd(t, v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

ll get(ll * t, int v, int tl, int tr, int l, int r)
{
	if (tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(t, v + v, tl, tm, l, r)
		+ get(t, v + v + 1, tm + 1, tr, l, r);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	ll ans = 0ll;
	for (int i = 1; i <= n; i++)
	{
		ll cnt = get(t, 1, 1, n, a[i], n);
		upd(t, 1, 1, n, a[i], 1);
		upd(T, 1, 1, n, a[i], cnt);
		ans += get(T, 1, 1, n, a[i] + 1, n);
	}
	printf(I64, ans);
}
