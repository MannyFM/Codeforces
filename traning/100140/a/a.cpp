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

struct edge {
	int to;
	ll c, f;
	int rv;
};

int n, m;
int s, t;
int us[maxn];
vector <edge> g[maxn];

void add_edge(int s, int t, int c) {
	edge a = {t, c, 0, (int)g[t].size()};
	edge b = {s, 0, 0, (int)g[s].size()};
	g[s].pb(a);
	g[t].pb(b);
};

ll dfs(int v, ll flow) {
//	printf("%d " I64 "\n", v, flow);
	if (v == t || !flow)
		return flow;
	us[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int & to = g[v][i].to;
		if (us[to] || g[v][i].c <= g[v][i].f)
			continue;
		ll now = dfs(to, min(flow, g[v][i].c - g[v][i].f));
		if (!now)
			continue;
		int j = g[v][i].rv;
		g[v][i].f += now;
		g[to][j].f -= now;
		return now;
	}
	return 0;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	s = 1, t = n;
	ll ans = 0;
	while (1) {
		ll flow = dfs(s, linf);
		if (!flow)
			break;
		ans += flow;
		for (int i = 1; i <= n; i++)
			us[i] = 0;
	}
	printf(I64, ans);
}
