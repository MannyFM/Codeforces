
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

int n, m;
ll a[maxn][maxn], b[maxn][maxn];

ll sum(int x1, int y1, int x, int y)
{
	if (x > n || y > m)
		return linf;
	x1--, y1--;
	return b[x][y] + b[x1][y1] - b[x][y1] - b[x1][y];
}

vector <pii> v;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf(I64, &a[i][j]);
			b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
		}
	int k;
	scanf("%d", &k);
	for (int i = 1; i * i <= k; i++)
		if (k % i == 0)
		{
			v.pb(mp(i, k / i));
			if (i * i != k)
				v.pb(mp(k / i, i));
		}
	ll ans = linf;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			for (pii p : v)
				ans = min(ans, sum(x, y, x + p.F - 1, y + p.S - 1));
	printf(I64, ans);
}

