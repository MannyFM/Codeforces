
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2010;
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
//#define fn

//int cur;

vector <ll> dp[maxn];
int mx;
int MX = -inf;

ll rec(int n, int last)
{
	if (n == 0)
	{
		/*
		for (int x : v)
			printf("%d ", x);
		puts("");
		*/
		//cerr << ++cur << " ";
		return 1;
	}
	if (n * 2 < mx)
		return 0;
	MX = max(MX, n);
	if (dp[n][last] != -1)
		return dp[n][last];
	ll & ans = dp[n][last];
	ans = 0;
	for (int x = last - 1; x * 2 >= mx; x--)
		ans += rec(n - x, x);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		mx = i;
		for (int j = 0; j <= n - i; j++)
			dp[j].assign(n, -1);
		ans += rec(n - i, i);
	}
	printf(I64, ans);
}
