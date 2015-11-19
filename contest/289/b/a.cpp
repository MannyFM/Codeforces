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
//#define fn ""

int n, m, d;
int a[150][150], ans = inf, cur;
set <int> s;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			s.insert(a[i][j]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int x = i; x <= n; x++)
				for (int y = j; y <= m; y++)
					if (abs(a[i][j] - a[x][y]) % d != 0)
					{
						puts("-1");
						return 0;
					}
	for (int x : s)
	{
		cur = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cur += abs(x - a[i][j]) / d;
		ans = min (ans, cur);
	}
	printf("%d", ans);
}
