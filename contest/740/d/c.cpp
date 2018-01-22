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

int const k_mx = 22;
int n, m;
int a[maxn];
vector <pii> g[maxn];
int in[maxn], out[maxn], T;
int ans[maxn];
ll D[maxn];
typedef pair <ll, pii> ev;
vector <ev> E;

void dfs(int v) {
	E.pb({D[v] - a[v], {0, v}});
	E.pb({D[v], {1, v}});
	in[v] = ++T;
	for (pii to : g[v]) {
		D[to.F] = D[v] + to.S;
		dfs(to.F);
	}
	out[v] = T;
}

int t[maxn];
void upd(int i, int x) {
	while (i <= n) {
		t[i] += x;
		i |= i + 1;
	}
}

int get(int i) {
	int ans = 0;
	while (i > 0) {
		ans += t[i];
		i = (i & (i + 1)) - 1;
	}
	return ans;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 2; i <= n; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		g[p].pb({i, w});
	}
	dfs(1);
	sort(all(E));
	for (ev e : E) {
		int v = e.S.S;
		int open = e.S.F;
		if (!open) {
			upd(in[v], 1);
		} else {
			ans[v] = get(out[v]) - get(in[v] - 1);
			if (D[v] - a[v] <= D[v])
				ans[v]--;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}
