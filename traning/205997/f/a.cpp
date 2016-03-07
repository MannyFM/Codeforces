
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5050;
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

ll norm(ll & x)
{
	while (x >= inf)
		x -= inf;
	if (x < 0)
		x += inf;
	return x;
}

int n, A[maxn];
int nxt[maxn][maxn];
ll dp[maxn][maxn], pre[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char c;
		scanf(" %c", &c);
		A[i] = c - '0';
	}
	for (int i = 1; i <= n + 1; i++)
		nxt[i][n + 1] = inf;
	for (int i = n; i > 0; i--)
		for (int j = n; j > i; j--)
		{
			if (A[i] != A[j])
				nxt[i][j] = i;
			else
				if (j < n)
					nxt[i][j] = nxt[i + 1][j + 1];
				else
					nxt[i][j] = inf;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = 1;
	for (int c = 1; c <= n; c++)
		for (int d = c + 1; d <= n; d++)
		{
			ll & x = pre[c][d];
			if (!A[c])
			{
				x = pre[c - 1][d];
				continue;
			}
			int a = 2 * c - d - 1;
			int b = c - 1;
			x = pre[b][b] - pre[max(0, a)][b];
			norm(x);
			if (a > 0)
			{
				int y = nxt[a][c];
				if (y < c && A[y] < A[y + c - a])
					x += pre[a][b] - pre[a - 1][b];
			}
			x += dp[c - 1][d];
			norm(x);
		}
	ll ans = 0ll;
	for (int i = 1; i <= n; i++)
	{
		ans += pre[i][n] - pre[i - 1][n];
		norm(ans);
	}
	printf(I64, ans);
}

