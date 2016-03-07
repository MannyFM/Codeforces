
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
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

struct edge
{
	int F, S, id;
	edge() { F = S = id = 0; }
	edge(int F, int S) : F(F), S(S), id(0) {}
	edge(int F, int S, int id) : F(F), S(S), id(id) {}
};

int N, M;
vector <edge> g[maxlen];

void djikstra(int s, int t)
{
	vector <int> d(N + 1, inf), p(N + 1, -1), k(N + 1, 0);
	d[s] = 0;
	set <pii> se;
	se.insert({d[s], s});
	while (!se.empty())
	{
		int v = se.begin() -> S;
		se.erase(se.begin());
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int & to = g[v][i].F, & cost = g[v][i].S;
			if (d[to] > d[v] + cost)
			{
				se.erase({d[to], to});
				d[to] = d[v] + cost;
				p[to] = v;
				k[to] = g[v][i].id;
				se.insert({d[to], to});
			}
		}
	}
	assert(d[t] < inf);
	vector <int> ans;
	int v = t;
	while (v != s)
	{
		if (k[v])
			ans.pb(k[v]);
		v = p[v];
	}
	reverse(all(ans));
	printf("%d\n%d\n", d[t], (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
	puts("");
}

map <int, int> id;

void add_edge(int a, int b, int c, int i = 0)
{
	if (!id.count(a))
		id[a] = ++N;
	if (!id.count(b))
		id[b] = ++N;
	a = id[a], b = id[b];
	g[a].pb({b, c, i});
}

int L, n;
int x[maxn], d[maxn], t[maxn], p[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &L);
	set <int> X = {0, L};
	add_edge(0, L, L);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", x + i, d + i, t + i, p + i);
		if (x[i] >= p[i])
		{
			add_edge(x[i] - p[i], x[i] + d[i], t[i] + p[i], i);
			X.insert(x[i] - p[i]);
			X.insert(x[i] + d[i]);
		}
	}
	int last = -1;
	for (int x : X)
	{
		if (last != -1)
		{
			add_edge(last, x, abs(x - last));
			add_edge(x, last, abs(x - last));
		}
//		printf("id[%d]=%d\n", x, id.count(x) ? id[x] : -1);
		last = x;
	}
	djikstra(id[0], id[L]);
}

