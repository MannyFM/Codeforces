
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
#define fn "d"

int dp[maxn][maxn];
int n, a[maxn];

int rec(int i, int r)
{
	if (!i)
		return 1;
	int & ans = dp[i][r];
	if (ans != -1)
		return ans;
	ans = 0;
	for (int j = max(i + i - r + 1, 1); j < i; j++)
		ans = (ans + rec(j - 1, i)) % inf;

}

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
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int last = 1; last <= n; last++)
		ans = (ans + rec(last, n)) % inf;
	printf("%d", ans);
}

