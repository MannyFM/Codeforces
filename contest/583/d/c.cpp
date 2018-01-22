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

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int n, t;
int a[maxn];
int dp[350];
int last[350], now[350];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int step = 1;
	for (; step <= t; step++)
	{
		for (int i = 0; i < n; i++)
			last[i] = now[i];
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j <= a[i % n]; j++)
				cur = max(cur, dp[j]);
			cur++;
			dp[a[i % n]] = cur;
			now[i] = cur;
		}
		bool ok = true;
		
		for (int i = 0; i < n; i++)
			printf("%d ", last[i]);
		puts("");
		for (int i = 0; i < n; i++)
			printf("%d ", now[i]);
		puts("\n");
		
		for (int i = 0; i < n; i++)
			if (last[i] + 1 != now[i])
			{
				ok = false;
				break;
			}
		if (ok)
			break;
		
	}
	printf("%d\n", step);
	step = min(step, t);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, now[i]);
	printf("%d", ans + t - step);
}
