
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 100 + 12
#define maxb 100 * 	100 + 12
#define shift 100 * 100 + 1
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define LOCAL

int d[maxn][2 * maxb];
int n, k, a[maxn], b[maxn];

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i);
	for (int i = 2; i < maxn; i++)
		for (int j = 0; j < 2 * maxb; j++)
			d[i][j] = -inf;
	for (int i = 1; i <= n; i++)
		for (int bal = 0; bal <= 2 * shift; bal++)
		{
			d[i + 1][bal] = max(d[i + 1][bal], d[i][bal]);
			if (d[i][bal] + a[i] > d[i + 1][bal + a[i] - b[i] * k])
			{
				//printf("%d %d %d %d\n", i, bal + a[i] - b[i] * k - shift, d[i + 1][bal + a[i] - b[i] * k], d[i][bal] + a[i]);
				d[i + 1][bal + a[i] - b[i] * k] = d[i][bal] + a[i];
			}
		}
	printf("%d", !d[n + 1][shift] ? -1 : d[n + 1][shift]);
}
