
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

map <int, ll> cnt, dp[2];

int n, k;
int a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % k)
		{
			cnt[a[i]]++;
			continue;
		}
		dp[1][a[i]] += dp[0][a[i] / k];
		dp[0][a[i]] += cnt[a[i] / k];
		cnt[a[i]]++;
	}
	/*
	for (auto x : cnt)
		printf("[%d %d] ", x.F, x.S);
	puts("");
	for (auto x : dp[0])
		printf("[%d %d] ", x.F, x.S);
	puts("");
	for (auto x : dp[1])
		printf("[%d %d] ", x.F, x.S);
	puts("");
	*/
	ll ans = 0ll;
	for (auto x : dp[1])
		ans += x.S;
	printf(I64, ans);
}
