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
#define fn "inevit"

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int n, m;
int is[maxn];
vector <pii> g[maxn];
vector <int> ans;
int us[maxn], tin[maxn], fup[maxn], timer;

void dfs(int v, int p = -1) {
	us[v] = 1;
	tin[v] = fup[v] = timer++;
	for (pii & x : g[v]) {
		int & to = x.F;
		if (to == p)
			continue;
		if (us[to])
			umin(fup[v], tin[to]);
		else {
			dfs(to, v);
			umin(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				is[x.S] = 1;
			}
		}
	}
//	printf("%d: t:%d f:%d\n", v, tin[v], fup[v]);
}

int S, T;

bool dfs2(int v) {
	if (v == T)
		return 1;
	us[v] = 1;
	for (pii & x : g[v]) {
		int & to = x.F;
		if (!us[to] && dfs2(to)) {
			if (is[x.S])
				ans.pb(x.S);
			return 1;
		}
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
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb({y, i});
		g[y].pb({x, i});
	}
	S = 1, T = n;
	dfs(S);
	memset(us, 0, sizeof(us));
	
	dfs2(S);
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
}
