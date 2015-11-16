
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
#define fn "forest"

int n, m, a[110][110];
ll dp[110][110][110];

ll rec(int i, int j, int pi, int pj, int up, int lvl = 0)
{
	for (int i = 0; i < lvl; i++) printf(" ");
		printf("i:%d j:%d u:%d y:" I64 "\n", i, j, up, dp[i][j][up]);
	if (up < a[i][j])
		return linf;
	if (up == a[i][j])
		return 0ll;
	ll & ans = dp[i][j][up];
	if (ans != -1)
		return ans;
	ans = linf;
	ll con = rec(i, j, -1, -1, up - 1, lvl + 1);
	if (con >= linf)
		return ans = linf;
	con++;
	if (i + 1 <= n && (i + 1 != pi || j != pj))
		ans = min(ans, rec(i + 1, j, i, j, up, lvl + 1) + con);
	if (j + 1 <= m && (i != pi || j + 1 != pj))
		ans = min(ans, rec(i, j + 1, i, j, up, lvl + 1) + con);
	if (i >= 2 && (i - 1 != pi || j != pj))
		ans = min(ans, rec(i - 1, j, i, j, up, lvl + 1) + con);
	if (j >= 2 && (i != pi || j - 1 != pj))
		ans = min(ans, rec(i, j - 1, i, j, up, lvl + 1) + con);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int MX = -1000;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), MX = max(MX, a[i][j]);
	memset(dp, -1, sizeof(dp));
	ll ans = -linf;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int mx = MX; mx > a[i][j]; mx--)
			{
				ll cur = rec(i, j, -1, -1, mx);
				if (cur != linf)
				{
					printf("i:%d j:%d mx:%d c:" I64 "\n", i, j, mx, cur);
					ans = max(ans, cur);
				}
			}
	printf(I64, ans);
}
