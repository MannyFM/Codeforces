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

int n, m, k;
int boss[maxn], sz[maxn];

int who(int x) {
	if (x == boss[x])
		return x;
	return boss[x] = who(boss[x]);
}

void merge(int x, int y) {
	x = who(x);
	y = who(y);
	if (x == y)
		return;
	if (sz[x] > sz[y])
		swap(x, y);
	boss[x] = y;
	if (sz[x] == sz[y])
		sz[y]++;
}

int t[maxn], x[maxn], y[maxn], ans[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		boss[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
	}
	for (int i = 1; i <= k; i++) {
		char s[100];
		scanf("%s %d %d", s, x + i, y + i);
		t[i] = s[0] == 'c';
	}
	for (int i = k; i > 0; i--) {
		if (t[i])
			merge(x[i], y[i]);
		else
			ans[i] = who(x[i]) == who(y[i]);
	}
	for (int i = 1; i <= k; i++)
		if (!t[i])
			puts(ans[i] ? "YES" : "NO");
	return 0;
}
