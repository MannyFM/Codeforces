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

int const maxn = 1010;
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(3e18 + 12);
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
bool gg[maxn][maxn];
set<int> hor[maxn], ver[maxn];
int shor[maxn][maxn], sver[maxn][maxn];
int dp[maxn][maxn];
pii s, t;
queue<pii> q;

bool can(int x, int y, int xx, int yy) {
	if (x == xx) {
		if (y > yy)
			swap(y, yy);
		return shor[x][yy] == shor[x][y];
	}
	if (y == yy) {
		if (x > xx)
			swap(x, xx);
		return sver[xx][y] == sver[x][y];
	}
	return 0;
}

int bfs() {
	q.push(s);
	dp[s.F][s.S] = 0;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
//		printf("(%d %d)\n", p.F, p.S);
		for (auto it = hor[p.F].begin(); it != hor[p.F].end(); ) {
			int j = *it;
			if (!can(p.F, p.S, p.F, j)) {
				it++;
				continue;
			}
			int cost = (abs(p.S - j) + k - 1) / k;
			dp[p.F][j] = dp[p.F][p.S] + cost;
			q.push({p.F, j});
			it = hor[p.F].erase(it);
			ver[p.S].erase(p.F);
		}
		for (auto it = ver[p.S].begin(); it != ver[p.S].end(); ) {
			int i = *it;
			if (!can(p.F, p.S, i, p.S)) {
				it++;
				continue;
			}
			int cost = (abs(p.F - i) + k - 1) / k;
			dp[i][p.S] = dp[p.F][p.S] + cost;
			q.push({i, p.S});
			it = ver[p.S].erase(it);
			hor[p.F].erase(p.S);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", dp[i][j]);
//		puts("");
//	}
	return dp[t.F][t.S];
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c;
			scanf(" %c", &c);
			gg[i][j] = c == '#';
			hor[i].insert(j);
			ver[j].insert(i);
			dp[i][j] = -1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			shor[i][j] = shor[i][j - 1] + gg[i][j];
			sver[i][j] = sver[i - 1][j] + gg[i][j];
		}
	scanf("%d%d%d%d", &s.F, &s.S, &t.F, &t.S);
	printf("%d\n", bfs());
}

