//
// Created by Manny, Alibek Manabayev
// Alibek.manabayev@gmail.com, Alibek.manabayev@nu.edu.kz
// Copyright 2016 A-3. All rights reserved.
//   ________                                             __  ___                       
//  /_  __/ /_  ___  ________     _      ______ ______   /  |/  /___ _____  ____  __  __
//   / / / __ \/ _ \/ ___/ _ \   | | /| / / __ `/ ___/  / /|_/ / __ `/ __ \/ __ \/ / / /
//  / / / / / /  __/ /  /  __/   | |/ |/ / /_/ (__  )  / /  / / /_/ / / / / / / / /_/ / 
// /_/ /_/ /_/\___/_/   \___/    |__/|__/\__,_/____/  /_/  /_/\__,_/_/ /_/_/ /_/\__, /  
//                                                                             /____/   

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(1e5 + 12);
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
#define rt(x)                                                                  \
  {                                                                            \
    puts(x);                                                                   \
    exit(0);                                                                   \
  }
//#define fn ""

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int S, T;

struct edge {
	int to;
	ll flow, cap;
};
vector <edge> E;
vector <int> g[maxn];

int d[maxn], q[maxn], ptr[maxn];

bool bfs() {
	int qh = 0, qt = 0;
	memset(d, -1, sizeof(d));
	d[S] = 0;
	q[qt++] = S;
	while (qh < qt && d[T] == -1) {
		int v = q[qh++];
//		printf("%d:", v);
		for (int i = 0; i < (int)g[v].size(); i++) {
			int id = g[v][i], to = E[id].to;
			if (d[to] == -1 && E[id].flow < E[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[T] != -1;
}

ll dfs(int v, ll flow) {
	if (!flow || v == T)
		return flow;
	for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
		int id = g[v][ptr[v]], to = E[id].to;
		if (d[to] != d[v] + 1)
			continue;
		ll now = dfs(to, min(flow, E[id].cap - E[id].flow));
		if (now) {
			E[id].flow += now;
			E[id ^ 1].flow -= now;
			return now;
		}
	}
	return 0;
}

ll Dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())
			break;
		memset(ptr, 0, sizeof(ptr));
		while (ll pushed = dfs(S, linf))
			flow += pushed;
	}
	return flow;
}

void add_edge(int x, int y, ll cap) {
	edge a = {y, 0, cap};
	edge b = {x, 0, 0};
	g[x].pb(E.size());
	E.pb(a);
	g[y].pb(E.size());
	E.pb(b);
}

int n, k;
int a[maxn], b[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	S = 0, T = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		add_edge(S, i, a[i]);
		add_edge(i, S, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		add_edge(i, T, b[i]);
		add_edge(T, i, b[i]);
	}
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y + n, linf);
	}
	ll flow = Dinic();
	printf(I64, flow);
}

