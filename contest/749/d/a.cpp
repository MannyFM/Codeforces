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

int n;
set <pii> bids;
set <int> person[maxn];

void del(int x) {
	if (person[x].empty())
		return;
	auto it = person[x].end(); it--;
	bids.erase({*it, x});
}

void add(int x) {
	if (person[x].empty())
		return;
	auto it = person[x].end(); it--;
	bids.insert({*it, x});
}

void solve(int k, vector <int> & v) {
	if (bids.empty()) {
		puts("0 0");
		return;
	}
	auto it = bids.end(); it--;
	int p = it -> S; it--;
	int ps = (bids.size() > 1) ? (it -> F) : 0;
	int bid = * person[p].upper_bound(ps);
//	printf("%d|", ps);
	printf("%d %d\n", p, bid);
	return;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		person[x].insert(y);
	}
	for (int i = 1; i <= n; i++)
		add(i);
	int m, k;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		vector <int> v(k + 1, 0);
		for (int j = 1; j <= k; j++)
			scanf("%d", &v[j]);
		for (int j = 1; j <= k; j++)
			del(v[j]);
		solve(k, v);
		for (int j = 1; j <= k; j++)
			add(v[j]);
	}

}
