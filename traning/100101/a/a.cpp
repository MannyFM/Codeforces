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

int const maxn = int(1e7 + 12);
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
//#define fn "sum0"

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

ll A[maxn], a[maxn];
ll b0, b1;

ll sum(int l, int r) {
	if (l > r)
		swap(l, r);
	printf("[%d %d]=" I64 "\n", l, r, A[r] - A[l - 1]);
	return A[r] - A[l - 1];
}

int n, x, y;
int m, z, t;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d" I64, &n, &x, &y, a);
	scanf("%d%d%d" I64, &m, &z, &t, &b0);
	ll mod1 = (1ll << 16), mod2 = (1ll << 30);
	A[0] = a[0];
	for (int i = 1; i < n; i++) {
		a[i] = (x * a[i - 1] + y) % mod1;
		A[i] = A[i - 1] + a[i];
	}
//	for (int i = 0; i < n; i++)
//		printf(I64 " ", a[i]);
//	puts("");
//	for (int i = 0; i < n; i++)
//		printf(I64 " ", A[i]);
//	puts("");

	b1 = (z * b0 + t + mod2) % mod2;
	ll ans = 0;
	for (int i = 0; i < m; i++) {
//		printf("[" I64 "; " I64 "]=" I64 "\n", b[2 * i] % n, b[2 * i + 1] % n,
//				sum(b[2 * i] % n, b[2 * i + 1] % n));
		ans += sum(b0 % n, b1 % n);
		b0 = (z * b1 + t + mod2) % mod2;
		b1 = (z * b0 + t + mod2) % mod2;
	}
	printf(I64, ans);
}

