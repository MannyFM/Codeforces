#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
//#define fn ""

int n, m;
int a[550][550];
set <int> prs;
bool pr[maxn + 15];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	memset(pr, 1, sizeof pr);
	pr[0] = pr[1] = 0;
	for (ll i = 2; i < maxn; i++)
	{
		if (pr[i])
		{
			for (ll j = i * i; j < maxn; j += i)
				pr[j] = 0;
			prs.insert(i);
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			a[i][j] = *prs.lower_bound(x) - x;
		}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	*/
	int ans = inf;
	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		for (int j = 0; j < m; j++)
			cur += a[i][j];
		ans = min(ans, cur);
	}
	for (int j = 0; j < m; j++)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
			cur += a[i][j];
		ans = min(ans, cur);
	}
	printf("%d", ans);
}
