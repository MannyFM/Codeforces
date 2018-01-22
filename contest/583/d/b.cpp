#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 200;
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
//#define fn ""

int n, t;
int a[maxn];
int dp[350], tp[450];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int ans = 0;
	for (int i = 0; i < n * t; i++)
	{
		int cur = 0;
		for (int j = 0; j <= a[i % n]; j++)
			cur = max(cur, dp[j]);
		cur++;
		dp[a[i % n]] = cur;
		ans = max(ans, cur);
		/*
		printf("%d ", cur);
		if (i % n == n - 1)
			putchar(' ');
		*/
	}
	printf("\n%d", ans);
}
