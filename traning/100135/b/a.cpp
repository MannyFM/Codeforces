
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
#define fn "lepus"

int n, dp[maxn];
char s[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	scanf("%s", s);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == -1)
			continue;
		if (s[i + 1] != 'w')
			dp[i + 1] = max(dp[i] + (s[i + 1] == '"'), dp[i + 1]);
		if (s[i + 3] != 'w')
			dp[i + 3] = max(dp[i] + (s[i + 3] == '"'), dp[i + 3]);
		if (s[i + 5] != 'w')
			dp[i + 5] = max(dp[i] + (s[i + 5] == '"'), dp[i + 5]);
	}
	printf("%d", dp[n - 1]);
}
