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
int const mod = int(1e9 + 7);
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
//#define fn ""

int n, k, d;
int dp[110][3];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	dp[0][0] = 1;
	scanf("%d%d%d", &n, &k, &d);
	for (int sum = 0; sum <= n; sum++)
	{
		for (int now = 1; now <= k && sum + now <= n; now++)
		{
			dp[sum + now][1] = (dp[sum][1] + dp[sum + now][1]) % mod;
			if (now >= d)
				dp[sum + now][1] = (dp[sum][0] + dp[sum + now][1]) % mod;
			else
				dp[sum + now][0] = (dp[sum][0] + dp[sum + now][0]) % mod;
		}
	}
	printf("%d", dp[n][1]);
}
