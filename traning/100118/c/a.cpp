
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
#define fn "fortification"

int n, pr[maxn], clr[maxn], m;
vector <int> g[maxn];

bool dfs(int v)
{
	clr[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (clr[to] == 2 || to == pr[v])
			continue;
		if (clr[to] == 1)
		{
			pr[to] = v;
			cerr << to << '\n';
			return 1;
		}
		if (clr[to] == 0)
		{
			pr[to] = v;
			if (dfs(to))
				return 1;
		}
	}
	clr[v] = 2;
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		//freopen(fn".out", "w", stdout);
	#endif
	ll ans = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!clr[i])
		{
			cerr << i << "-";
			if (!dfs(i))
			{
				cerr << '\n';
				continue;
			}
			int y = pr[i], cnt = 1;
			printf("i:%d y:%d\n", i, y);
			while (i != y)
			{
				printf("%d -> ", y);
				y = pr[y], cnt++;
			}
			ans = (ans * cnt) % inf;
			printf("%d: %d\n", i, cnt);
		}
	}
	printf(I64, ans);
}
