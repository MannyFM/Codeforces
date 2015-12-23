
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
//#define fn ""

int n, m;
int a[maxn];
vector <int> v[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
	{
		if (a[i - 1] != a[i])
			v[a[i - 1]].pb(a[i]);
		if (a[i + 1] != a[i])
			v[a[i + 1]].pb(a[i]);
	}
	ll sum = 0ll, ans = 0ll;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].empty())
			continue;
		sort(v[i].begin(), v[i].end());
		int y = v[i][v[i].size() / 2];
		ll old = 0ll, now = 0ll;
		for (int j = 0; j < int(v[i].size()); j++)
		{
			old += abs(i - v[i][j]);
			now += abs(y - v[i][j]);
		}
		ans = max(ans, old - now);
		sum += old;
	}
	printf(I64, sum / 2 - ans);
}

