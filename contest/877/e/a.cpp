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

int T[4 * maxn], W[4 * maxn];
int add[4 * maxn];
int a[maxn];

void push(int v, int tl, int tr) {
	if (!add[v])
		return;
	swap(T[v], W[v]);
	if (tl < tr) {
		add[v + v] ^= 1;
		add[v + v + 1] ^= 1;
	}
	add[v] = 0;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		if (a[tl])
			T[v]++;
		else
			W[v]++;
		add[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	T[v] = T[v + v] + T[v + v + 1];
	W[v] = W[v + v] + W[v + v + 1];
	add[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (tl > tr || r < tl || tr < l)
		return;
	if (l <= tl && tr <= r) {
		add[v] ^= 1;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r);
	upd(v + v + 1, tm + 1, tr, l, r);
	push(v + v, tl, tm);
	push(v + v + 1, tm + 1, tr);
	T[v] = T[v + v] + T[v + v + 1];
	W[v] = W[v + v] + W[v + v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (tl > tr || r < tl || tr < l)
		return 0;
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int n, N;
vector<int> g[maxn];
int L[maxn], R[maxn];
int A[maxn];

void dfs(int v) {
	L[v] = ++N;
	A[N] = v;
	for (int to : g[v])
		dfs(to);
	R[v] = N;
}

int p[maxn], t[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", p + i);
		g[p[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", t + i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		a[i] = t[A[i]];
//		printf("%d ", A[i]);
	}
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("(%d %d) ", L[i], R[i]);
//	puts("");

	build(1, 1, N);
	char s[10];
	int M, v;
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%s %d", s + 1, &v);
		if (s[1] == 'g') {
			int ans = get(1, 1, N, L[v], R[v]);
			printf("%d\n", ans);
		}
		if (s[1] == 'p') {
			upd(1, 1, N, L[v], R[v]);
		}
	}
}

