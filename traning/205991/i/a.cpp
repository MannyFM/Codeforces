
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

ll add(ll & x, ll y)
{
	x += y;
	while (x >= inf)
		x -= inf;
	return x;
}

int n, k;
ll dp[2050][2050];
vector <int> v[2050];

ll rec(int pos, int last)
{
	if (pos == 1)
		return 1ll;
	ll & ans = dp[pos][last];
	if (ans != -1)
		return ans;
	ans = 0ll;
	for (int x : v[last])
		add(ans, rec(pos - 1, x));
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
		for (int j = 1; j * j <= i; j++)
		{
			if (i % j)
				continue;
			v[i].pb(j);
			if (j * j != i)
				v[i].pb(i / j);
		}
	}
	memset(dp, -1, sizeof(dp));
	ll ans = 0ll;
	for (int x = 1; x <= n; x++)
		add(ans, rec(k, x));
	printf(I64, ans);
}

