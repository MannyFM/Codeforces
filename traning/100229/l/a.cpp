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

int n, m;
int boss[maxn];
vector <pii> g[maxn];

void add_edge(int x, int y) {
	int cost = boss[x] != boss[y];
	if (x % 2 == 0)
		cost *= 2;
	g[x].pb({y, cost});
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", boss + i);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}

	int s = 1, t = n;
	vector <int> d(n + 1, inf), pr(n + 1, -1);
	d[s] = 0;
	set <pii> se;
	se.insert({d[s], s});
	while (!se.empty()) {
		int x = se.begin() -> S;
		se.erase(se.begin());
		for (pii y : g[x]) {
			int to = y.F, cost = y.S;
			if (d[to] > d[x] + cost) {
				se.erase({d[to], to});
				d[to] = d[x] + cost;
				pr[to] = x;
				se.insert({d[to], to});
			}
		}
	}
	if (d[t] == inf) {
		rt("impossible");
	}
	vector <int> path;
	int x = t;
	do {
		path.pb(x);
		x = pr[x];
	} while (x != s);
	path.pb(s);
	reverse(all(path));
	printf("%d %d\n", d[t], (int)path.size());
	for (int x : path)
		printf("%d ", x);
}
