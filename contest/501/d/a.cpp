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

int T[4 * maxn];
int a[maxn];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		T[v] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	T[v] = T[v + v] + T[v + v + 1];
}

void upd(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		T[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	T[v] = T[v + v] + T[v + v + 1];
}

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return sum(v + v, tl, tm, l, r)
		+ sum(v + v + 1, tm + 1, tr, l, r);
}

int kth(int v, int tl, int tr, int k) {
	if (tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	if (T[v + v] >= k)
		return kth(v + v, tl, tm, k);
	else
		return kth(v + v + 1, tm + 1, tr, k - T[v + v]);
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
}
