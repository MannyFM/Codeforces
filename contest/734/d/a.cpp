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
typedef map<ll, ll> mii;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

ll const maxn = ll(5e5 + 12);
ll const maxlen = ll(2e6 + 12);
ll const inf = ll(1e9 + 7);
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
ll u = linf, d = -linf, l = -linf, r = linf;
ll ur = linf, dr = linf, dl = linf, ul = linf;

bool B(ll a, ll b) {
	return (a == b || a == -b);
}

bool R(ll a, ll b) {
	return (!a || !b);
}

void add(ll a, ll b) {
	if (!a) {
		if (b > 0)
			umin(u, b);
		if (b < 0)
			umax(d, b);
	}
	if (!b) {
		if (a > 0)
			umin(r, a);
		if (a < 0)
			umax(l, a);
	}
	if (a == b) {
		if (a > 0)
			umin(ur, a);
		else
			umin(dl, -a);
	}
	if (a == -b) {
		if (a > 0)
			umin(dr, a);
		else
			umin(ul, -a);
	}
}

bool canR(ll a, ll b) {
	if (!a) {
		if (b > 0)
			return u >= b;
		else
			return d <= b;
	}
	if (!b) {
		if (a > 0)
			return r >= a;
		else
			return l <= a;
	}
	return 0;
}

bool canB(ll a, ll b) {
	if (a == b) {
		if (a > 0)
			return a <= ur;
		else
			return -a <= dl;
	}
	if (a == -b) {
		if (a > 0)
			return a <= dr;
		else
			return -a <= ul;
	}
	return 0;
}

ll x[maxn], y[maxn];
char s[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	ll X, Y;
	scanf("%d" I64 I64, &n, &X, &Y);
	for (ll i = 1; i <= n; i++) {
		scanf(" %c" I64 I64, s + i, x + i, y + i);
		x[i] -= X;
		y[i] -= Y;
		add(x[i], y[i]);
	}
	for (ll i = 1; i <= n; i++) {
//		prllf(I64 " " I64 "\n", x[i], y[i]);
		if ((s[i] == 'B' || s[i] == 'Q') && B(x[i], y[i])){
			if (canB(x[i], y[i]))
				rt("YES");
		}
		if ((s[i] == 'R' || s[i] == 'Q') && R(x[i], y[i])){
			if (canR(x[i], y[i]))
				rt("YES");
		}
	}
	puts("NO");
}
