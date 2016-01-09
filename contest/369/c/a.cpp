
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
//#define fn ""

int n, cnt;
vector <int> g[maxn], b[maxn];
bool ans[maxn];

bool dfs(int v, int pr = 0)
{
	bool pushed = 0;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int & to = g[v][i], is = b[v][i];
		if (pr == to)
			continue;
		bool f = dfs(to, v);
		pushed |= f;
		if (!is || f)
			continue;
		ans[to] = 1;
		pushed = 1;
		cnt++;
	}
	return pushed;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		z--;
		g[x].pb(y);
		b[x].pb(z);
		g[y].pb(x);
		b[y].pb(z);
	}
	dfs(1);
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (ans[i])
			printf("%d ", i);
}

