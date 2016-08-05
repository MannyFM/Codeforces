
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
vector <int> g[maxn];
int clr[maxn];
bool ok = 1;

void dfs(int v) {
	for (int to : g[v]) {
		if (clr[to] == -1) {
			clr[to] = !clr[v];
			dfs(to);
		} else
			if (clr[to] == clr[v]) {
				ok = 0;
				return;
		}
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(clr, -1, sizeof(clr));
	for (int i = 1; i <= n; i++)
		if (clr[i] == -1) {
			clr[i] = 0;
			dfs(i);
	}
	if (!ok) {
		puts("-1");
		return 0;
	}
	vector <int> ans[2];
	for (int i = 1; i <= n; i++) {
		ans[clr[i]].pb(i);
	}
	for (int i = 0; i < 2; i++) {
		printf("%d\n", (int)ans[i].size());
		for (int to : ans[i])
			printf("%d ", to);
		puts("");
	}
}

