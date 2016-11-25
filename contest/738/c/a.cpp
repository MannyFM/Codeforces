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

int const maxn = int(2e5 + 12);
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

int n, k, s, t;
int c[maxn], v[maxn];
int g[maxn];

bool f(int w) {
	ll T = 0;
	for (int i = 1; i <= k; i++) {
		int S = g[i] - g[i - 1];
		if (w < S)
			return 0;
		int y = min(S, w - S);
		T += 2 * S - y;
	}
	return T <= t;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", c + i, v + i);
	for (int i = 1; i <= k; i++)
		scanf("%d", g + i);
	sort(g + 1, g + 1 + k);
	g[++k] = s;
	int tl = 0, tr = inf;
	while (tr - tl > 1) {
		int tm = (tl + tr) >> 1;
		if (f(tm))
			tr = tm;
		else
			tl = tm;
	}
//	printf("[%d %d]", tl, tr);
	if (!f(tr))
		rt("-1");
	int w = tr, ans = -1;
	for (int i = 1; i <= n; i++) {
		if (v[i] < w)
			continue;
		if (ans == -1 || c[i] < c[ans])
			ans = i;
	}
	printf("%d", ans == -1 ? -1 : c[ans]);
}
