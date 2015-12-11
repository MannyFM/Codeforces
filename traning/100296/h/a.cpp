
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5050;
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
#define fn "secure"

int n, m;
vector <pii> g[maxn];
int base[maxn], pr[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n,  &m);
	int S = 0,  T = n + 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", base + i);
		if (base[i] == 1)
			g[S].pb(mp(i, 0));
		if (base[i] == 2)
			g[i].pb(mp(T, 0));
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	vector <int> D(n + 3, inf);
	D[S] = 0;
	set <pii> se;
	se.insert(mp(D[S], S));
	while (!se.empty())
	{
		int v = se.begin() -> S;
		se.erase(se.begin());
		for (int i = 0; i < int(g[v].size()); i++)
		{
			int &to = g[v][i].F, &cost = g[v][i].S;
			if (D[to] > D[v] + cost)
			{
				se.erase(mp(D[to], to));
				D[to] = D[v] + cost;
				se.insert(mp(D[to], to));
				pr[to] = v;
			}
		}
	} 
	if (D[T] == inf)
	{
		puts("-1");
		return 0;
	}
	int f = T, s = pr[T];
	while (pr[f])
		f = pr[f];
	printf("%d %d %d", f, s, D[T]);
}
