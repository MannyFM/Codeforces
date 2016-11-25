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

int n, c[maxn];
vector <int> g[maxn];
set <pii> se[maxn];
int boss[maxn];

int who(int x) {
	if (x == boss[x])
		return x;
	return boss[x] = who(boss[x]);
}

bool merge(int x, int y) {
	x = who(x);
	y = who(y);
	if (x == y)
		return 0;
	if (se[x].size() > se[y].size())
		swap(x, y);
	boss[x] = y;
	for (auto t :se[x])
		se[y].insert(t);
	se[x].clear();
	return 1;
}

set <pii> d;

void clean(int v) {
//	printf("%d +\n", v);
	d.erase({-se[v].size(), v});
	vector <pii> nr;
	for (auto to : se[v]) {
		nr.pb(to);
		//printf("%d<->%d, ", to.F, to.S);
	}
	//puts("\n-----");
	for (auto to : nr) {
		int bbs = who(to.S);
		d.erase({-se[to.S].size(), to.S});
		se[v].erase({to.F, to.S});
		se[bbs].erase({to.S, to.F});
		merge(v, to.S);
	}
	int bs = who(v);
//	nr.pb(v);
//	printf("bs:%d\n", bs);
//	for (auto i : se[bs])
//		printf("%d<->%d, ", i.F, i.S);
//	puts("\n__________");
//	for (int to : nr)
//		se[bs].erase(to);
	if (!se[bs].empty())
		d.insert({-se[bs].size(), bs});
}

vector <pii> E;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		boss[i] = i;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E.pb({x, y});
		if (c[x] != c[y]) {
			se[x].insert({x, y});
			se[y].insert({y, x});
		}
		E.pb({x, y});
	}
	for (pii i : E) {
		if (c[i.F] == c[i.S])
			merge(i.F, i.S);
	}
	for (int i = 1; i <= n; i++) {
		int bs = who(i);
		d.insert({-se[bs].size(), bs});
	}
	int ans = 0;
	while (d.size() > 1) {
		ans++;
//		puts("+++++++++++");
//		for (pii i : d) {
//			printf("%d %d:\n", i.F, i.S);
//			for (auto to : se[i.S])
//				printf("%d<->%d, ", to.F, to.S);
//			puts("");
//		}
//		puts("+++++++++++");
		clean(d.begin() -> S);
	}
	printf("%d\n", ans);
}

