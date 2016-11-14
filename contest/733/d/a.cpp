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

map <pii, set<pii>> id;
int ans;
int X = -1, Y = -1;

int f(int x, int y, int z) {
	return min(min(x, y), z);
}

void solve(int x, int y) {
	if (x > y)
		swap(x, y);
	auto se = id.find({x, y});
	auto it1 = (se -> S).begin();
	auto it2 = it1; it2++;
	if (umax(ans, f(x, y, -(it1 -> F + it2 -> F)))) {
		X = it1 -> S;
		Y = it2 -> S;
	}
}

void add(int x, int y, int z, int i) {
	if (x > y)
		swap(x, y);
	id[{x, y}].insert({-z, i});
}

int n, x[maxn], y[maxn], z[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", x + i, y + i, z + i);
		add(x[i], y[i], z[i], i);
		add(x[i], z[i], y[i], i);
		add(y[i], z[i], x[i], i);
		if (umax(ans, f(x[i], y[i], z[i])))
			X = i;
	}
	for (int i = 1; i <= n; i++) {
		solve(x[i], y[i]);
		solve(y[i], z[i]);
		solve(z[i], x[i]);
	}
//	printf("%d\n", ans);
	if (Y == -1) {
		printf("1\n%d", X);
	} else {
		printf("2\n%d %d", X, Y);
	}
}
