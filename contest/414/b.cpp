
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 2000 + 12
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int const mod = 1000000007;
int n, k;
int d[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		d[1][i] = 1;
	for (int t = 2; t <= k; t++)
		for (int i = 1; i <= n; i++)
			for (int x = i; x <= n; x += i)
				d[t][x] = (d[t][x] + d[t - 1][i]) % mod;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + d[k][i]) % mod;
	printf("%d", ans);
}
