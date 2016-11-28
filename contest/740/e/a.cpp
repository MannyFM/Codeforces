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

int const maxn = int(3e5 + 12);
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
	int L, M, R;
};

item t[4 * maxn];
ll a[maxn];

template<class T>
int sign(T x) {
	return x ? (x < 0 ? -1 : 1) : 0;
}

void recalc(int v, int tl, int tr) {
	int tm = (tl + tr) >> 1;
	t[v].M = max(t[v + v].M, t[v + v + 1].M);
	if (!a[tm]|| !a[tm + 1] || sign(a[tm]) < sign(a[tm + 1])) {
		t[v].L = t[v + v].L;
		t[v].R = t[v + v + 1].R;
	} else {
		umax(t[v].M, t[v + v].R + t[v + v + 1].L);
		t[v].L = t[v + v].L;
		if (t[v + v].M == tm - tl + 1)
			t[v].L += t[v + v + 1].L;
		t[v].R = t[v + v + 1].R;
		if (t[v + v + 1].M == tr - tm)
			t[v].R += t[v + v].R;
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		int x = !!a[tl];
		t[v] = {x, x, x};
//	printf("[%d %d]=%d %d %d\n", tl, tr, t[v].L, t[v].M, t[v].R);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	recalc(v, tl, tr);
//	printf("[%d %d]=%d %d %d\n", tl, tr, t[v].L, t[v].M, t[v].R);
}

void upd(int v, int tl, int tr, int pos, int d) {
	if (pos < tl || tr < pos)
		return;
	if (tl == tr) {
		a[tl] += d;
		int x = !!a[tl];
		t[v] = {x, x, x};
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, d);
	else
		upd(v + v + 1, tm + 1, tr, pos, d);
	recalc(v, tl, tr);
}

int n, ar[maxn];
int m;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", ar + i);
	for (int i = 1; i < n; i++)
		a[i] = ar[i + 1] - ar[i];
	if (n > 1)
		build(1, 1, n - 1);
//	printf("%d %d %d\n", t[1].L, t[1].M, t[1].R);
	scanf("%d", &m);
	for (int i = 1, l, r, d; i <= m; i++) {
		scanf("%d%d%d", &l, &r, &d);
		if (n == 1) {
			puts("1");
			continue;
		}
		if (l != 1)
			upd(1, 1, n - 1, l - 1, d);
		if (r != n)
			upd(1, 1, n - 1, r, -d);
		printf("%d\n", t[1].M + 1);
	}
}

