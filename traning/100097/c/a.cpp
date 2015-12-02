
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
#define fn "coins"

int sum[32][32];
int n, m, k;

int get(int x, int y, int x1, int y1)
{
	x--, y--;
	return sum[x][y] + sum[x1][y1] - sum[x][y1] - sum[x1][y];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char x;
			scanf(" %c", &x);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (x == 'o');
		}
	int ans = inf;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			for (int x1 = 0; x1 + x < n; x1++)
				for (int y1 = 0; y1 + y < m; y1++)
				{
					if (get(x + 1, y + 1, n - x1, m - y1) != k)
						continue;
					int cur = min(2 * x + x1, 2 * x1 + x) + min(2 * y + y1, 2 * y1 + y);
					ans = min(ans, cur);
				}
	if (ans >= inf)
		ans = -1;
	printf("%d", ans);
		
}
