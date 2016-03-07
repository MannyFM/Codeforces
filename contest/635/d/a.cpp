
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

int n, f[2], k, m;
ll t[2][4 * maxn];

void upd(int k, int v, int tl, int tr, int pos, int val)
{
	if (tl == tr)
	{
		t[k][v] += val;
		if (t[k][v] > f[k])
			t[k][v] = f[k];
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(k, v + v, tl, tm, pos, val);
	else
		upd(k, v + v + 1, tm + 1, tr, pos, val);
	t[k][v] = t[k][v + v] + t[k][v + v + 1];
}

ll get(int k, int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return 0ll;
	if (l <= tl && tr <= r)
		return t[k][v];
	int tm = (tl + tr) >> 1;
	return get(k, v + v, tl, tm, l, r)
		+ get(k, v + v + 1, tm + 1, tr, l, r);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d", &n, &k, &f[1], &f[0], &m);
	for (int i = 1; i <= m; i++)
	{
		int t, l, r;
		scanf("%d%d", &t, &l);
		if (t == 1)
		{
			scanf("%d", &r);
			upd(0, 1, 1, n, l, r);
			upd(1, 1, 1, n, l, r);
		}
		else
		{
			ll L = get(0, 1, 1, n, 1, l - 1);
			ll R = get(1, 1, 1, n, l + k, n);
//			printf(I64 " " I64 " ", L, R);
			printf(I64 "\n", L + R);
		}
	}
}

