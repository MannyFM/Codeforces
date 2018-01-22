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
int shor[maxn][maxn], sver[maxn][maxn];
int dp[maxn][maxn];
pii s, t;
queue<pii> q;

int bfs() {
	q.push(s);
	dp[s.F][s.S] = 0;
	while (!q.empty() && dp[t.F][t.S] == inf) {
		int x = q.front().F;
		int y = q.front().S;
//		printf("(%d %d)", x, y);
		q.pop();
		for (int i = x - 1; i > 0 && abs(x - i) <= k; i--) {
			if (!gg[i][y] || dp[i][y] <= dp[x][y] + 1)
				break;
			dp[i][y] = dp[x][y] + 1;
			q.push({i, y});
		}
		for (int i = x + 1; i <= n && abs(x - i) <= k; i++) {
//			printf("[%d %d  %d %d] ", i, y, gg[i][y], dp[i][y]);
			if (!gg[i][y] || dp[i][y] <= dp[x][y] + 1)
				break;
			dp[i][y] = dp[x][y] + 1;
			q.push({i, y});
		}
		for (int j = y - 1; j > 0 && abs(y - j) <= k; j--) {
			if (!gg[x][j] || dp[x][j] <= dp[x][y] + 1)
				break;
			dp[x][j] = dp[x][y] + 1;
			q.push({x, j});
		}
		for (int j = y + 1; j <= m && abs(y - j) <= k; j++) {
			if (!gg[x][j] || dp[x][j] <= dp[x][y] + 1)
				break;
			dp[x][j] = dp[x][y] + 1;
			q.push({x, j});
		}
//		puts("");
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", dp[i][j]);
//		puts("");
//	}
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
		}
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			dp[i][j] = inf;
	scanf("%d%d%d%d", &s.F, &s.S, &t.F, &t.S);
	printf("%d\n", bfs());
}

