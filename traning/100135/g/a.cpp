
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
#define fn "longpath"

vector <int> g[maxn];
int n, us[maxn], m;

int dfs(int v)
{
	if (us[v] != -1)
		return us[v];
	int & ans = us[v];
	us[v] = 0;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		ans = max(ans, dfs(to) + 1);
	}
	return us[v] = ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
	memset(us, -1, sizeof(us));
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (us[i] == -1)
			ans = max(ans, dfs(i));
	printf("%d", ans);
}
