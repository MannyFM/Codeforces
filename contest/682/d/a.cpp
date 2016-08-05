
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

int n, m, k, ans;
char s[maxn], t[maxn];
int dp[maxn][maxn][12][2];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j][1][1] = s[i] == t[j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int cnt = 1; cnt <= k; cnt++)
				for (int end = 0; end < 2; end++) {
					if (s[i + 1] == t[j + 1]) {
						if (end)
							umax(dp[i + 1][j + 1][cnt][1], dp[i][j][cnt][1] + 1);
						umax(dp[i + 1][j + 1][cnt + 1][1], dp[i][j][cnt][end] + 1);
					}
					umax(dp[i + 1][j][cnt][0], dp[i][j][cnt][end]);
					umax(dp[i][j + 1][cnt][0], dp[i][j][cnt][end]);
					umax(dp[i + 1][j + 1][cnt][0], dp[i][j][cnt][end]);
				}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			for (int cnt = 1; cnt <= k; cnt++)
//				for (int end = 0; end < 2; end++)
//					if (dp[i][j][cnt][end])
//						printf("dp[%d][%d][%d][%d]=%d\n", i, j, cnt, end, dp[i][j][cnt][end]);
	for (int cnt = 1; cnt <= k; cnt++) {
		umax(ans, dp[n][m][cnt][0]);
		umax(ans, dp[n][m][cnt][1]);
	}
	printf("%d", ans);
}

