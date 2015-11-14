
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

int n, dp[502][502], a[502][502];

int rec(int i, int j)
{
	if (i == n)
		return a[i][j];
	int & cur = dp[i][j];
	if (cur != -1)
		return cur;
	cur = rec(i + 1, j);
	if (j + 1 <= i + 1)
		cur = max(cur, rec(i + 1, j + 1));
	return cur += a[i][j];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d", rec(1, 1));
}
