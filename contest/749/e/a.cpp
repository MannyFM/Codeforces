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

ll t[4 * maxn];

void upd(int v, int tl, int tr, int pos, ll x) {
	if (tl == tr) {
		t[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || r < tl)
		return 0ll;
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

ld f(ld len) {
	return len * (len - 1) / 4; 
}

int n, a[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	ld sum_expect = 0, diff_expect = 0;
	ll segs = n * (n + 1ll) / 2;
	ll invs = 0;
	for (int i = n; i > 0; i--) {
		ll cur = get(1, 1, n, 1, a[i]);
		invs += cur;
		sum_expect += f(n - i + 1);
		diff_expect += (sum_expect - invs) / segs;
		upd(1, 1, n, a[i], n - i + 1);
//		printf("%d " I64 " " I64 " %.12lf %.12lf\n", i, cur, invs, (double)sum_expect, (double)diff_expect);
	}
//	for (int i = 1; i <= n; i++)
//		printf(I64 " ", get(1, 1, n, i, i));
//	puts("");
	for (int i = 1; i <= n; i++)
		upd(1, 1, n, a[i], 0);
	invs = 0;
	for (int i = n; i > 0; i--) {
		invs += get(1, 1, n, 1, a[i]);
		upd(1, 1, n, a[i], 1);
	}
	printf("%.12lf", (double)(invs + diff_expect));
}
