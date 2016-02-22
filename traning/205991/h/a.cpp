
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

ll dp[2][110][110];
int n, k, d;

ll rec(int lvl, int n, int ok)
{
	if (!n)
		return ok;
	ll & ans = dp[ok][lvl][n];
	if (ans != -1)
		return ans;
	ans = 0ll;
	int mx = min(n, k);
	for (int i = 1; i <= mx; i++)
	{
		ans += rec(lvl + 1, n - i, ok | (i >= d));
		while (ans >= inf)
			ans -= inf;
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &k, &d);
	memset(dp, -1, sizeof(dp));
	ll ans = rec(1, n, 0);
	printf(I64, ans);
}

