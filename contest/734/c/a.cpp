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

struct item {
	ll val;
	item * l, * r;
	item () {
		val = inf;
		l = r = 0;
	}
	item (ll x) {
		val = x;
		l = r = 0;
	}
};

typedef item * pitem;

ll val(pitem t) {
	return t ? t -> val : linf;
}

void upd(pitem & t, int tl, int tr, int pos, ll x) {
	if (!t) {
		t = new item(linf);
	}
	if (tl == tr) {
		t -> val = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(t -> l, tl, tm, pos, x);
	else
		upd(t -> r, tm + 1, tr, pos, x);
	t -> val = min(val(t -> l), val(t -> r));
}

ll get(pitem t, int tl, int tr, int l, int r) {
	if (!t || l > r || tr < l || r < tl)
		return linf;
	if (l <= tl && tr <= r)
		return val(t);
	int tm = (tl + tr) >> 1;
	return min(get(t -> l, tl, tm, l, r),
			get(t -> r, tm + 1, tr, l, r));
}

pitem root;
int n, m, k, x, s;
ll a[maxn], b[maxn], d[maxn], c[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &x, &s);
	ll L = linf, R = -linf;
	for (int i = 1; i <= m; i++)
		scanf(I64, a + i);
	for (int i = 1; i <= m; i++) {
		scanf(I64, b + i);
		umin(L, b[i]);
		umax(R, b[i]);
	}
//	printf("[%d %d]\n", L, R);
	for (int i = 1; i <= m; i++)
		upd(root, L, R, b[i], a[i]);
	for (int i = 1; i <= k; i++)
		scanf(I64, c + i);
	for (int i = 1; i <= k; i++)
		scanf(I64, d + i);
	ll ans = n * 1ll * x;
	for (int i = 1; i <= k; i++) {
		if (d[i] > s)
			break;
		int left = max(0ll, n - c[i]);
		if (!left) {
			umin(ans, 0ll);
			break;
		}
		ll y = get(root, L, R, L, s - d[i]);
		if (y >= inf)
			y = x;
//		printf(I64 ": l:%d %d\n", left * 1ll * y, left, y);
		umin(ans, left * 1ll * y);
	}
	ll y = get(root, L, R, L, s);
	if (y < inf)
		umin(ans, y * 1ll * n);
	printf(I64 "\n", ans);
}
