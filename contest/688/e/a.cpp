
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 501;
int const maxb = maxn * maxn;
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
//#define all(x) x.begin(), x.end()
#define ex(x) {puts(x); exit(0);}
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

int n, k;
int N;
int a[maxn];
bool dp[2][maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), N += a[i];
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int now = i & 1;
		int last = !now;
		for (int x = 0; x <= k; x++)
			for (int y = 0; y <= x; y++) {
				dp[now][x][y] = dp[last][x][y];
				if (x >= a[i]) {
					dp[now][x][y] |= dp[last][x - a[i]][y];
					if (y >= a[i])
						dp[now][x][y] |= dp[last][x - a[i]][y - a[i]];
				}
			}
	}
	vector <int> ans;
	int now = n & 1;
	for (int i = 0; i <= k; i++)
		if (dp[now][k][i])
			ans.pb(i);
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
}

