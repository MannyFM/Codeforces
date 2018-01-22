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


int n, a[maxn];
int next[maxn];
int last[maxn];
char s[maxn];

map <char, int> id;

int f(char x) {
	if (!id.count(x))
		id[x] = id.size();
	return id[x];
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i++)
		a[i] = f(s[i]);
	for (int i = 0; i < (int)id.size(); i++)
		last[i] = inf;
	for (int i = n; i > 0; i--) {
		next[i] = last[a[i]];
		last[a[i]] = i;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", next[i]);
//	puts("");
//	for (int i = 0; i < (int)id.size(); i++)
//		printf("%d ", last[i]);
//	puts("");
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 0; j < (int)id.size(); j++)
			umax(cur, last[j]);
		last[a[i]] = next[i];
		umin(ans, cur - i + 1);
//		printf("%d %d\n", i, cur);
	}
	printf("%d", ans);
}
