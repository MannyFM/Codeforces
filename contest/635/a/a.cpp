
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

int n, m, k, l, x, y;
int a[11][11], b[11][11];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &l, &k);
	for (int i = 1; i <= l; i++)
	{
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
	int ans = 0;
	for (int x1 = 1; x1 <= n; x1++)
	for (int y1 = 1; y1 <= m; y1++)
	for (int x2 = x1; x2 <= n; x2++)
	for (int y2 = y1; y2 <= m; y2++)
	{
		int g = b[x2][y2] + b[x1 - 1][y1 - 1] - b[x2][y1 - 1] - b[x1 - 1][y2];
		ans += g >= k;
	}
	printf("%d", ans);
}

