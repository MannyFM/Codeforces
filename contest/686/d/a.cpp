
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(3e5 + 12);
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, m;
set <pii> se[maxn];
vector <int> g[maxn];
int sz[maxn];
int Q[maxn];

int dfs(int v) {
	sz[v] = 1;
	for (int to : g[v])
		sz[v] += dfs(to);
	se[v].insert({sz[v], v});
	for (int to : g[v]) {
		if (se[v].size() < se[to].size())
			swap(se[v], se[to]);
		for (pii x : se[to])
			se[v].insert(x);
	}
//	printf("%d:", v);
//	for (auto x : se[v])
//		printf("(%d %d) ", x.F, x.S);
//	puts("");
	auto it = se[v].lower_bound({(sz[v] + 1) / 2, 0});
	Q[v] = it -> S;
	return sz[v];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		int pr;
		scanf("%d", &pr);
		g[pr].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= m; i++) {
		int v;
		scanf("%d", &v);
		printf("%d\n", Q[v]);
	}
}

