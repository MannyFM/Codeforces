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

int const maxn = int(5e5 + 12);
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

#define in(x, n) ((1 << (x)) & (n))

int n;
int t[maxn], x[maxn];
int p[maxn];
int mx = 10;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c%d", &c, x + i);
		if (c == '|')
			t[i] = 1;
		if (c == '^')
			t[i] = 2;
		if (c == '&')
			t[i] = 3;
	}
	for (int j = 0; j < mx; j++) {
		p[j] = -1;
		for (int i = 0; i < n; i++) {
			if (t[i] == 1) {
				if (in(j, x[i])) {
					p[j] = 1;
				}
			}
			if (t[i] == 2) {
				if (in(j, x[i])) {
					if (p[j] == -1)
						p[j] = -2;
					else
						p[j] ^= 1;
				}
			}
			if (t[i] == 3) {
				if (!in(j, x[i])) {
					p[j] = 0;
				}
			}
		}
//		printf("%d ", p[j]);
	}
//	puts("");
//	for (int j = 0; j < mx; j++)
//		printf("%d ", p[j]);
//	puts("");
	int OR = 0;
	int XOR = 0;
	int AND = 0;
	for (int j = 0; j < mx; j++) {
		AND |= (1 << j);
		if (p[j] == -1)
			continue;
		if (p[j] == -2)
			XOR |= (1 << j);
		if (p[j] == 1)
			OR |= (1 << j);
		if (p[j] == 0) {
			OR |= (1 << j);
			XOR |= (1 << j);
		}
//		if (p[j] == 0)
	}
	printf("2\n");
	printf("| %d\n", OR);
	printf("^ %d\n", XOR);
}

