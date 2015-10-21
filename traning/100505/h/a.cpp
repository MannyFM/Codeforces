
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
#define fn "run"

struct edge
{
	ll a, b, c;
	edge()
	{
		a = b = c = 0;
	}
	edge(int x, int y, int z)
	{
		a = x, b = y, c = z;
	}
};

int n, m, k;
set <pair <int, int> > g[maxn];
vector <edge> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].insert(mp(c, b));
		g[b].insert(mp(c, a));
		v.pb(edge(a, b, c));
	}
	k--;
	ll ans = linf;
	for (edge e : v)
	{
		if (g[e.a].size() > 1)
		{
			auto it = g[e.a].begin();
			pii f = *it;
			if (f.S == e.b)
				f = *(++it);
			ll x = min(f.F + 0ll, e.c), y = max(f.F + 0ll, e.c);
			ans = min(ans, y * k / 2 + x * (k + 1) / 2 + 0ll);
		}
		
		if (g[e.b].size() > 1)
		{
			auto it = g[e.b].begin();
			pii f = *it;
			if (f.S == e.a)
				f = *(++it);
			int x = min(f.F + 0ll, e.c), y = max(f.F + 0ll, e.c);
			ans = min(ans, y * k / 2 + x * (k + 1) / 2 + 0ll);
		}
	}
	printf(I64, ans);
}
