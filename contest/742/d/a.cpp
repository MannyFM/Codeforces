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
#define rank MyLittleRank
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
vector <int> g[maxn];
ll w[maxn], b[maxn];
ll W, B, Wmax;
int us[maxn];
vector <pll> ve;

void dfs(int v) {
	us[v] = 1;
	ve.pb({w[v], b[v]});
	W += w[v];
	B += b[v];
	for (int to : g[v])
		if (!us[to])
			dfs(to);
}

ll can[maxn], ncan[maxn];

void solve(int v) {
	W = B = 0;
	ve.clear();
	dfs(v);
	ve.pb({W, B});
	for (int i = 0; i <= Wmax; i++)
		ncan[i] = can[i];
	for (pll x : ve) {
		for (int i = Wmax; i >= x.F; i--)
			if (can[i - x.F] != -1)
				umax(ncan[i], can[i - x.F] + x.S);
//		printf("(" I64 " " I64 ") ", x.F, x.S);
	}
//	puts("");
	for (int i = 0; i <= Wmax; i++)
		can[i] = ncan[i];
//	for (int i = 0; i <= Wmax; i++)
//		if (can[i] != i)
//			printf("can[%d]=" I64 "\n", i, can[i]);
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d" I64, &n, &m, &Wmax);
	for (int i = 1; i <= n; i++) {
		scanf(I64, w + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf(I64, b + i);
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	memset(can, -1, sizeof(can));
	can[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (us[i])
			continue;
		solve(i);
	}
	ll ans = 0;
	for (int i = 0; i <= Wmax; i++)
		if (can[i] != -1)
			umax(ans, can[i]);
	printf(I64, ans);
}

