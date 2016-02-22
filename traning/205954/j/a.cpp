
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

int T[4 * maxn];

void upd(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr)
	{
		T[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	T[v] = T[v + v] + T[v + v + 1];
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int n, a[maxn];
map <int, int> cnt;
int l[maxn], r[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		l[i] = ++cnt[a[i]];
	cnt.clear();
	for (int i = n; i > 0; i--)
	{
		r[i] = ++cnt[a[i]];
		upd(1, 1, n, r[i], 1);
	}
	ll ans = 0ll;
	for (int i = 1; i <= n; i++)
	{
		upd(1, 1, n, r[i], -1);
		ans += get(1, 1, n, 1, l[i] - 1);
	}
	printf(I64, ans);
}

