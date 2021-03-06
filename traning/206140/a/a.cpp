
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 550;
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

ll dp[maxn][maxn];
int n, m, b, mod;
int a[maxn];

inline void norm(ll & x)
{
	while (x >= mod)
		x -= mod;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			for (int k = 0; k + a[i] <= b; k++)
			{
				dp[j + 1][k + a[i]] += dp[j][k];
				norm(dp[j + 1][k + a[i]]);
			}
	}
	ll ans = 0;
	for (int i = 0; i <= b; i++)
	{
		ans += dp[m][i];
		norm(ans);
	}
	printf("%d", ans);
}

