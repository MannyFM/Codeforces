
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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

int dp[maxn], n;
int pr[maxn];
set <int> se;

void gen(int cur)
{
	if (cur > n)
		return;
	se.insert(cur);
	dp[cur] = 1;
	pr[cur] = cur;
	gen(cur * 10);
	gen(cur * 10 + 1);
}

int rec(int x)
{
	if (x == 1)
		return 1;
	int & ans = dp[x];
	if (ans != -1)
		return ans;
	ans = inf;
	for (int y : se)
	{
		if (y > x)
			break;
		if (umin(ans, rec(x - y) + 1))
			pr[x] = y;
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	gen(1);
	rec(n);
	vector <int> ans;
	while (n)
	{
		ans.pb(pr[n]);
		n -= pr[n];
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
}

