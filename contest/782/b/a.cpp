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

int n, x[maxn], v[maxn];
ld L, R;

ld f(ld pos) {
	ld ans = .0;
	for (int i = 1; i <= n; i++)
		umax(ans, fabs(x[i] - pos) / v[i]);
	return ans;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	int ll = inf, rr = -inf;
	for (int i = 1; i <= n; i++) {
		scanf("%d", x + i);
		umin(ll, x[i]);
		umax(rr, x[i]);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", v +i);
	L = ld(ll), R = ld(rr);
	for (int step = 0; step <= 100; step++) {
		ld m1 = L + (R - L) / 3;
		ld m2 = R - (R - L) / 3;
		if (eps <= f(m2) - f(m1))
			R = m2;
		else
			L = m1;
	}
	printf("%.6f", (double)f(L));
//	printf("f(%.6f)=%.6f\n", (double)L, (double)f(L));
//	printf("f(%.6f)=%.6f\n", (double)R, (double)f(R));
}

