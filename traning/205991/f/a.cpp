
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
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, x[maxn], h[maxn];
map <int, int> dp;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", x + i, h + i);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d: ", x[i], h[i]);
		if (!dp.count(x[i]))
			dp[x[i]] = 1;
		if (!dp.count(x[i] + h[i]))
			dp[x[i] + h[i]] = 1;
		auto it = dp.lower_bound(x[i] - h[i]);
		if (!dp.empty())
		{
			if (it != dp.begin())
				it--;
			printf("+%d", it -> F);
			if (it -> F < x[i] - h[i])
				umax(dp[x[i]], it -> S + 1);
			if (it -> F < x[i])
				umax(dp[x[i]], it -> S);
		}
		it = dp.lower_bound(x[i]);
		if (!dp.empty())
		{
			if (it != dp.begin())
				it--;
			printf(" %d:", it -> F);
			if (it -> F < x[i])
				umax(dp[x[i]], it -> S + 1),
				umax(dp[x[i] + h[i]], it -> S + 1);
		}
		for (pii y : dp)
			printf("(%d %d) ", y.F, y.S);
		puts("");
	}
	auto it = dp.end(); it--;
	printf("%d", it -> S);
}

