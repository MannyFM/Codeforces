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
int clr[maxn];

int who(int l) {
	if (boss[l] == l)
		return l;
	return boss[l] = who(boss[l]);
}

void merge(int l, int r) {
	l = who(l);
	r = who(r);
	if (l == r)
		return;
	if (sz[l] > sz[r])
		swap(l, r);
	boss[l] = r;
	if (sz[l] == sz[r])
		sz[r]++;
}

vector <int> g[maxn];
int us[maxn];
map <int, int> cnt;

void dfs(int v) {
	us[v] = 1;
	cnt[clr[v]]++;
	for (int to : g[v])
		if (!us[to])
			dfs(to);
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", clr + i), boss[i] = i;
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		merge(l, r);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int bos = who(i);
		ans += clr[bos] != clr[i];
	}
	for (int i = 1; i <= n; i++) {
		g[i].pb(who(i));
	}
	printf("%d", ans);
}
