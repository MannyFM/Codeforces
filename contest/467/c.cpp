#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5050;
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
#define sum(l, r) (pre[r] - pre[l - 1])
//#define fn ""

int n, m, k;
ll a[maxn], pre[maxn];
ll dp[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf(I64, &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = m; i <= n; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + pre[i] - pre[i - m]);
	printf(I64, dp[n][k]);
}
