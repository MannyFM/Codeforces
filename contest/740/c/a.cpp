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

struct item {
	int F, S;
	int mx;
};

item T[4 * maxn];

item operator + (item a, item b) {
	if (a.F == b.F)
		return {a.F, min(a.S, b.S), max(a.mx, b.mx)};
	item c = a.F < b.F ? a : b;
	c.mx = max(a.mx, b.mx);
	return c;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		T[v] = {-inf, tl, -inf};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	T[v] = T[v + v] + T[v + v + 1];
}

void upd(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		T[v] = {x, tl, x};
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	T[v] = T[v + v] + T[v + v + 1];
}

item get(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || r < tl)
		return {inf, inf, -inf};
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int n, m, a[maxn];
int L[maxn], R[maxn];
set <pair <int, pii>> se;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		se.insert({(r - l), {l, r}});
		L[i] = l;
		R[i] = r;
	}
	build(1, 1, n);
	while (!se.empty()) {
		int l = se.begin() -> S.F;
		int r = se.begin() -> S.S;
//		printf(" %d %d\n", l, r);
		se.erase(se.begin());
		while (1) {
			item g = get(1, 1, n, l, r);
//			printf(" %d %d %d\n", g.F, g.S, g.mx);
			if (g.F >= 0)
				break;
			int st = g.mx < 0 ? 0 : g.mx + 1;
//			printf("a[%d]=%d\n", g.S, st);
			upd(1, 1, n, g.S, st);
		}
//		for (int i = 1; i <= n; i++) {
//			item g = get(1, 1, n, i, i);
//			printf("%d ", g.mx < 0 ? 0 : g.mx);
//		}
//		puts("");
	}
	int ans = inf;
	for (int i = 1; i <= m; i++) {
		item g = get(1, 1, n, L[i], R[i]);
//		printf("[%d %d] %d\n", L[i], R[i], g.mx);
		umin(ans, g.mx + 1);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		item g = get(1, 1, n, i, i);
		printf("%d ", g.mx < 0 ? 0 : g.mx);
	}
}
