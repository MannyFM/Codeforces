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

int n, m, a[maxn], b[maxn];
vector <pii> ans;
int l = 1;

bool solve(int st) {
	if (l > n) {
		assert(0);
		return 0;
	}
	int r = l, cur = 0;
	while (cur < b[st]) {
		if (r > n) {
//			assert(0);
			return 0;
		}
		cur += a[r++];
	}
	if (cur != b[st]) {
//		assert(0);
		return 0;
	}
	if (l + 1 == r) {
		l = r;
		return 1;
	}
	int mx = -inf;
	for (int i = l; i < r; i++)
		umax(mx, a[i]);
	int j = -1;
	for (int i = l; i < r; i++) {
		if (a[i] != mx)
			continue;
		if (i > l && a[i] > a[i - 1])
			j = i;
		if (i + 1 < r && a[i] < a[i + 1])
			j = i;
	}
//	printf("[%d %d) %d\n", l, r, j);
	if (j == -1 && l + 1 < r) {
//		assert(0);
		return 0;
	}
	int L = j - 1, R = j + 1;
	cur = a[j];
	int eat = 0;
//	printf("[%d %d] [%d %d] %d\n", l, r, L, R, j);
	while (l <= L || R < r) {
		if (l <= L && cur > a[L]) {
			cur += a[L];
			ans.pb({st + (j - l) - eat, 0});
			eat++;
			L--;
		}
		if (R < r && cur > a[R]) {
			cur += a[R];
			ans.pb({st + (j - l) - eat, 1});
			R++;
		}
	}
	l = r;
	return 1;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	for (int j = 1; j <= m; j++) {
		if (!solve(j))
			rt("NO");
	}
//	if (i < n)
//		rt("NO");
	puts("YES");
	for (pii x : ans)
		printf("%d %c\n", x.F, !x.S ? 'L' : 'R');
}
