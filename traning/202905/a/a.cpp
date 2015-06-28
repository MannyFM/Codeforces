
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, m, t;
ll ans;
ll C[50][50];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int n = 0; n < 50; n++)
	{
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; k++)
			C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}
	/*
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("%d ", C[i][j]);
		puts("");
	}
	*/
	scanf("%d%d%d", &n, &m, &t);
	int boys = 4, girls;
	while (boys <= n && (t - boys > 0))
	{
		girls = t - boys;
		if (girls > m)
		{
			boys++;
			continue;
		}
		//printf("%d %d\n", boys, girls);
		//printf("%I64d %I64d\n", C[n][boys], C[m][girls]);
		ans += C[n][boys] * C[m][girls];
		boys++;
	}
	printf("%I64d", ans);
}
