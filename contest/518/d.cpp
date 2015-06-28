
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second

double dp[2020][2020];
int n, t;
double p, ans;

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> p >> t;
	dp[0][0] = 1;
	for (int i = 0; i <= t; i++)
		for (int j = 0; j <= min(n, i); j++)
			if (j == n)
				dp[i + 1][j] += dp[i][j];
			else
			{
				dp[i + 1][j + 1] += dp[i][j] * p;
				dp[i + 1][j] += dp[i][j] * (1 - p);
			}
	for (int j = 1; j <= n; j++)
		ans += dp[t][j] * j;
	printf("%0.8lf", ans);
}