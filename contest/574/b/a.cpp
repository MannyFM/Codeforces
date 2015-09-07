
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 4050;
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

int n, m, ans = inf;
vector <int> g[maxn];
bool can[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		can[a][b] = can[b][a] = 1;
	}
	for (int A = 1; A <= n; A++)
		for (int j = 0; j < int(g[A].size()); j++)
		{
			int B = g[A][j];
			if (g[B].size() > g[A].size())
				continue;
			for (int k = 0; k < int(g[B].size()); k++)
			{
				int C = g[B][k];
				if (!can[C][A])
					continue;
				int now = g[A].size() + g[B].size() + g[C].size() - 6;
				ans = min(ans, now);
			}
		}
	printf("%d", ans == inf ? -1 : ans);
}
