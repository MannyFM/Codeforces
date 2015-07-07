
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int ans[550];
int a[550][550];
int n, m, q;

void upd(int i)
{
	ans[i] = 0;
	int cur = 0;
	for (int j = 0; j < m; j++)
	{
		if (a[i][j])
			cur++;
		else
			cur = 0;
		ans[i] = max(ans[i], cur);
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		upd(i);
	for (int Q = 0; Q < q; Q++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		a[x][y] ^= 1;
		upd(x);
		int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, ans[i]);
		printf("%d\n", res);
	}
}
