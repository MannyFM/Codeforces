
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e3 + 12);
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

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
#define rank MyLittleRank
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
#define fn "f"

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

struct edge
{
	int a, b, id;
	edge() { a = b = id = 0;}
	edge(int a, int b, int id) : a(a), b(b), id(id) {}
};

int n, m, M;
vector <int> g[maxn];
vector <edge> e[2];
int us[maxn];
int boss[maxn], rank[maxn];
int U[maxlen], V[maxlen];

int who(int u)
{
	return boss[u] == u ? u : (boss[u] = who(boss[u]));
}

bool merge(int u, int v)
{
	u = who(u);
	v = who(v);
	if (u == v)
		return 0;
	if (rank[u] < rank[v])
		swap(u, v);
	boss[v] = u;
	if (rank[u] == rank[v])
		rank[u]++;
	return 1;
}

void dfs(int v, int clr)
{
	boss[v] = clr;
	for (int to : g[v])
		if (!boss[to])
			dfs(to, clr);
}

vector <int> ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &M);
	if (n % 2 == 0)
		rt("-1");
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		if (a == b)
			continue;
		if (c == 'M')
		{
			g[a].pb(b);
			g[b].pb(a);
		}
		U[i] = a;
		V[i] = b;
		e[c == 'S'].pb({a, b, i});
//		e[c == 'S'].pb({b, a, i});
	}
	int cnt = 0, need = 0, half = (n - 1) / 2;
	for (int i = 1; i <= n; i++)
		if (!boss[i])
			dfs(i, i), cnt++;
	need = half;
//	printf("%d %d\n", cnt, need);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", boss[i]);
//	puts("");
	if (cnt - 1 > half)
		rt("-1");
	for (auto x : e[1])
	{
		if (!need)
			break;
		if (!merge(x.a, x.b))
			continue;
//		printf("%d<->%d %d\n", x.a, x.b, -1);
		need--;
		ans.pb(x.id);
	}
	for (int i = 1; i <= n; i++)
		boss[i] = i, rank[i] = 0;
	for (int id : ans)
		assert(merge(U[id], V[id]));
	for (auto x : e[1])
	{
		if (!need)
			break;
		if (!merge(x.a, x.b))
			continue;
//		printf("%d<->%d %d\n", x.a, x.b, 1);
		need--;
		ans.pb(x.id);
	}
	if (need)
		rt("-1");
	need = half;
	for (auto x : e[0])
	{
		if (!need)
			break;
		if (!merge(x.a, x.b))
			continue;
//		printf("%d<->%d %d\n", x.a, x.b, 0);
		need--;
		ans.pb(x.id);
	}
	if (need)
		rt("-1");
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
}

