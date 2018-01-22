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
int dp[maxn][maxn];
pii s, t;
pii Q[maxn * maxn];
int qh, qt;

int bfs() {
	Q[qt++] = s;
	dp[s.F][s.S] = 0;
	while (qh < qt && dp[t.F][t.S] == inf) {
		int x = Q[qh].F;
		int y = Q[qh].S;
		qh++;
		for (int i = 1; i <= k; i++) {
			if (1 <= xx && xx <= n && !gg[xx][y] || dp[xx][y] <= dp[x][y] + 1 || abs(x - xx) > k)
				break;
			dp[xx][y] = dp[x][y] + 1;
			Q[qt++] = {xx, y};
		}
		for (int xx = x + 1; 1 <= xx && xx <= n; xx++) {
			if (!gg[xx][y] || dp[xx][y] <= dp[x][y] + 1 || abs(x - xx) > k)
				break;
			dp[xx][y] = dp[x][y] + 1;
			Q[qt++] = {xx, y};
		}
		for (int yy = y - 1; 1 <= yy && yy <= m; yy--) {
			if (!gg[x][yy] || dp[x][yy] <= dp[x][y] + 1 || abs(y - yy) > k)
				break;
			dp[x][yy] = dp[x][y] + 1;
			Q[qt++] = {x, yy};
		}
		for (int yy = y + 1; 1 <= yy && yy <= m; yy++) {
			if (!gg[x][yy] || dp[x][yy] <= dp[x][y] + 1 || abs(y - yy) > k)
				break;
			dp[x][yy] = dp[x][y] + 1;
			Q[qt++] = {x, yy};
		}
	}
	return dp[t.F][t.S] >= inf ? -1 : dp[t.F][t.S];
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
			gg[i][j] = c == '.';
			dp[i][j] = inf;
		}
	scanf("%d%d%d%d", &s.F, &s.S, &t.F, &t.S);
	printf("%d\n", bfs());
}

