
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 505;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
//double const pi = acos(-1);
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

int n, a[maxn];
pair <int, bool> dp[maxn][maxn];
int d1[maxn], d2[maxn];

bool check(int l, int r)
{
	int m = -1;
	if ((r - l + 1) & 1)
	{
		m = (l + r) / 2;
		return 2 * d1[m] - 1 >= r - l + 1;
	}
	else
	{
		m = (l + r + 1) / 2;
		return 2 * d2[m] >= r - l + 1;
	}
}

typedef pair <int, bool> pi;

pi min(pi a, pi b)
{
	if (a.F != b.F)
		return a.F < b.F ? a : b;
	return a.S >= b.S ? a : b;
}

pi rec(int l, int r)
{
	if (l > r)
		return mp(0, 0);
	if (check(l, r))
		return mp(1, 1);
	if (l == r)
		return mp(1, 1);
	pi & ans = dp[l][r];
	if (ans.F != -1)
		return ans;
	ans.F = inf;
	if (a[l] == a[r])
	{
		auto p = rec(l + 1, r - 1);
		if (!p.S)
			p.F++;
		ans = min(ans, p);
	}
	auto p = rec(l + 1, r);
	ans = min(ans, mp(rec(l + 1, r).F + 1, true));
	ans = min(ans, mp(rec(l, r - 1).F + 1, true));
	for (int i = l + 1; i < r; i++)
	{
		auto L = rec(l, i - 1), R = rec(i + 1, r - 1);
		int pts = L.F + R.F + 1;
		if (L.S || R.S)
			pts--;
		ans = min(ans, mp(pts, true));
	}
	printf("[%d %d] %d %d\n", l, r, ans.F, ans.S);
	return ans;
}


int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		int & r = d1[i];
		while (i - r >= 1 && i + r <= n && a[i - r] == a[i + r])
			r++;
	}
	for (int i = 2; i <= n; i++)
	{
		int & r = d2[i];
		while (i - r - 1 >= 1 && i + r <= n && a[i - r - 1] == a[i + r])
			r++;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", d1[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", d2[i]);
	puts("");
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = mp(-1, false);
	pi ans = rec(1, n);
	printf("%d", ans.F);
}

