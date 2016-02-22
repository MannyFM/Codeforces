
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2050;
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

int n, k;
vector <int> v[maxn];
ll dp[maxn][maxn];

inline void norm(ll & x)
{
	while (x >= inf)
		x -= inf;
}

ll rec(int pos, int last)
{
	if (pos == 1)
		return 1;
	ll & ans = dp[pos][last];
	if (ans != -1)
		return ans;
	ans = 0ll;
	for (int x : v[last])
	{
		ans += rec(pos - 1, x);
		norm(ans);
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int x = 1; x * x <= i; x++)
		{
			if (i % x)
				continue;
			v[i].pb(x);
			if (x * x != i)
				v[i].pb(i / x);
		}
	}
	memset(dp, -1, sizeof(dp));
	ll ans = 0ll;
	for (int i = 1; i <= n; i++)
	{
		ans += rec(k, i);
		norm(ans);
	}
	printf(I64, ans);
}

