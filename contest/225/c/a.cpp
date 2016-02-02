
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e3 + 12);
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

int h[maxn], a[maxn][maxn], sum[maxn];
int dp[2][maxn];
int n, m, x, y;
char s[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[i][j] == '#';
			h[j] += a[i][j];
		}
	for (int i = 1; i <= m; i++)
	{
		sum[i] = sum[i - 1] + h[i];
		dp[0][i] = dp[1][i] = inf;
	}
	//1 - White
	//2 - Black
	for (int i = 0; i < m; i++)
	{
		for (int j = x; j <= y; j++)
		{
			if (i + j > m)
				continue;
			int white = sum[i + j] - sum[i];
			int black = j * n - white;
			umin(dp[0][i + j], dp[1][i] + white);
			umin(dp[1][i + j], dp[0][i] + black);
		}
	}
	printf("%d", min(dp[0][m], dp[1][m]));
}

