
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 450;
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

bool G[maxn][maxn];
vector <int> g[maxn], t[maxn];
int n, m;
int d1[maxn], d2[maxn];
int q[maxn];
int qh, qt;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = G[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (G[i][j])
				g[i].pb(j);
			else
				t[i].pb(j);
			d1[i] = d2[i] = inf;
		}
	d1[1] = 0;
	q[qt++] = 1;
	while (qh < qt)
	{
		int v = q[qh++];
		for (int to : g[v])
			if (umin(d1[to], d1[v] + 1))
				q[qt++] = to;
	}
	d2[1] = 0;
	qh = qt = 0;
	q[qt++] = 1;
	while (qh < qt)
	{
		int v = q[qh++];
		for (int to : t[v])
			if (umin(d2[to], d2[v] + 1))
				q[qt++] = to;
	}
	int ans = max(d1[n], d2[n]);
	if (ans >= inf)
		ans = -1;
	printf("%d", ans);
}
