
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

#define maxn int(2e3 + 12)
#define maxb int(1e5)
#define inf int(1e9 + 7)
#define linf ll(2e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "negcycle"
#define LOCAL

int n, g[120][120], pr[120][120];

vi get(int i, int j)
{
	if (pr[i][j] == i)
	{
		vi ans = {i};
		return ans;
	}
	vi a, b;
	a = get(i, pr[i][j]);
	b = get(pr[i][j], j);
	for (auto v : b)
		a.pb(v);
	a.pb(j);
	return a;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		pr[i][j] = i;
	
	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (g[i][k] < maxb && g[k][j] < maxb)
		if (g[i][j] > g[i][k] + g[k][j])
		{
			g[i][j] = g[i][k] + g[k][j];
			pr[i][j] = k;
		}
	int v = -1;
	for (int i = 1; i <= n; i++)
		if (g[i][i] < 0)
			v = i;
	if (v == -1)
	{
		puts("NO");
		return 0;
	}
	printf("%d %d", v, pr[v][v]);
}