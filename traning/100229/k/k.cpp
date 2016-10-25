
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
#define fn "ladder"
#define LOCAL
#define F first
#define S second

int n, a[maxn], k;
int dp[maxn];

int rec(int i)
{
	if (i == n + 1)
		return 0;
	if (dp[i] != 0)
		return dp[i];
	int ans = -inf;
	for (int step = 1; step <= min(n - i + 1, k); step++)
		ans = max(ans, rec(i + step));
	dp[i] = ans + a[i];
	return dp[i];
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &k);
	printf("%d\n", rec(0));
}