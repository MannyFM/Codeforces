
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 110;
int const maxlen = int(2e6 + 12);
//int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

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
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
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

int n, m, k;
int c[maxn];
ll dp[maxn][maxn][maxn];
ll p[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(I64, &p[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			for (int g = 0; g <= m; g++)
				dp[i][j][g] = linf;
	if (!c[1])
		for (int i = 1; i <= m; i++)
			dp[1][1][i] = p[1][i];
	else
		dp[1][1][c[1]] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			if (c[i]) {
				umin(dp[i][j][c[i]], dp[i - 1][j][c[i]]);
				for (int col = 1; col <= m; col++)
					if (col != c[i])
						umin(dp[i][j][c[i]], dp[i - 1][j - 1][col]);
			} else {
				for (int col1 = 1; col1 <= m; col1++) {
//					printf("%d %d %d  " I64 " " I64 "\n", i, j, col1, dp[i][j][col1], dp[i - 1][j][col1] + p[i][col1]);
					umin(dp[i][j][col1], dp[i - 1][j][col1] + p[i][col1]);
					for (int col2 = 1; col2 <= m; col2++)
						if (col1 != col2)
							umin(dp[i][j][col1], dp[i - 1][j - 1][col2] + p[i][col1]);
				}
			}
		}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= k; j++)
//			for (int col = 1; col <= m; col++)
//				if (dp[i][j][col] < linf)
//					printf("dp[%d][%d][%d]=" I64 "\n", i, j, col, dp[i][j][col]);
	ll ans = linf;
	for (int i = 1; i <= m; i++)
		umin(ans, dp[n][k][i]);
	if (ans >= linf)
		ans = -1;
	printf(I64, ans);
}

