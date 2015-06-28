
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"
#define f first
#define s second

int n, a[200][200], k[200];
ll ans[200];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", k + i);
	int anss = inf;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%d", &a[i][j]);
			ans[i] += 5 * a[i][j] + 15;
		}
		anss = min(anss + 0ll, ans[i]);
	}
	printf("%d", anss);
}