
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
#define fn "floyd"
#define LOCAL

int n, g[120][120];

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
	
	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (g[i][k] < maxb && g[k][j] < maxb)
		if (g[i][j] > g[i][k] + g[k][j])
			g[i][j] = g[i][k] + g[k][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", g[i][j]);
		puts("");
	}
}