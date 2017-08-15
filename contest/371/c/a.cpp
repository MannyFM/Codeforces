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

int n[10], cnt[10], p[10];
ll R;
char s[150];

ll f(ll k) {
	ll cost = 0;
	for (int i = 1; i <= 3; i++) {
		if (n[i] < cnt[i] * 1ll * k)
			cost += (cnt[i] * 1ll * k - n[i]) * 1ll * p[i];
	}
	return cost;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%s", s + 1);
	for (int i = 1; i <= 3; i++)
		scanf("%d", n + i);
	for (int i = 1; i <= 3; i++)
		scanf("%d", p + i);
	scanf(I64, &R);
	int st = strlen(s + 1);
	for (int i = 1; i <= st; i++) {
		if (s[i] == 'B')
			cnt[1]++;
		if (s[i] == 'S')
			cnt[2]++;
		if (s[i] == 'C')
			cnt[3]++;
	}
	ll l = -1, r = (ll)1e13;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (f(m) <= R)
			l = m;
		else
			r = m;
	}
	printf(I64, l);
}

