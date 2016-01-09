
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
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

int dp[maxn][maxn];
int n, a[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char x;
		scanf(" %c", &x);
		a[i] = x - '0';
	}
	for (int i = 1; i <= n; i++)
		dp[1][i] = 1;
	for (int last = 1; last <= n; last++)
	{
		for (int i = last + 1; i <= n; i++)
		{
			if (!a[i] || !dp[last][i - 1])
				continue;
			for (int j = i + i - last; j <= n; j++)
				dp[i][j] = (dp[i][j] + dp[last][i - 1]) % inf;
			if (i + i - last - 1 <= n)
			{
				bool ok = 0;
				for (int k = last; k < i; k++)
					if (a[k] != a[k + i - last])
					{
						ok = a[k] < a[k + i - last];
						break;
					}
				if (ok)
					dp[i][i + i - last - 1] = (dp[i][i + i - last - 1] + dp[last][i - 1]) % inf;
			}
		}
	}
//	for (int last = 1; last <= n; last++)
//	{
//		for (int i = last; i <= n; i++)
//			printf("dp[%d][%d]=%d\n", last, i, dp[last][i]);
//	}
	int ans = 0;
	for (int last = 1; last <= n; last++)
		ans = (ans + dp[last][n]) % inf;
	printf("%d", ans);
}
