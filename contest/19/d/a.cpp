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

struct item {
	pii x;
	int prior, sz;
	int val;
	item * l, * r;
	item() {
		x = {0, 0};
		prior = sz = val = 0;
		l = r = 0;
	}
	item(int a, int b) :prior((rand() * 1ll * rand()) % inf), sz(0), val(b), l(0), r(0) {
		x = {a, b};
	}
};

typedef item * pitem;

int sz(pitem t) {
	return t ? t -> sz : 0;
}

int val(pitem t) {
	return t ? t -> val : 0;
}

void upd(pitem t) {
	if (!t)
		return;
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
	t -> val = max(t -> x.S, max(val(t -> l), val(t -> r)));
}

void merge(pitem & t, pitem l, pitem r) {
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l -> prior > r -> prior)
		merge(l -> r, l -> r, r), t = l;
	else
		merge(r -> l, l, r -> l), t = r;
	upd(t);
}

void split(pitem t, pitem & l, pitem & r, pii key) {
	if (!t) {
		l = r = 0;
		return;
	}
	if (key < (t -> x))
		split(t -> l, l, t -> l, key), r = t;
	else
		split(t -> r, t -> r, r, key), l = t;
	upd(t);
}

pitem most_left(pitem & t, int y) {
	if (!t || t -> val <= y)
		return 0;
	pitem ans = most_left(t -> l, y);
	if (ans)
		return ans;
	if (t -> x.S > y)
		return t;
	return most_left(t -> r, y);
}

void insert(pitem & t, int x, int y) {
	pitem it = new item(x, y);
	pitem t1, t2;
	split(t, t1, t2, {x, y});
	merge(t, t1, it);
	merge(t, t, t2);
}

//void remove(pitem & t, pii x) {
//	if (!t)
//		return;
//	if (t -> x == x) {
//		merge(t, t -> l, t -> r);
//		return;
//	}
//	remove(t -> x < x ? t -> l : t -> r, x);
//	upd(t);
//}

void out(pitem t, int lvl = 0) {
	return;
	if (!t)
		return;
	for (int i = 0; i < lvl; i++)
		putchar(' ');
	printf("(%d %d)\n", t -> x.F, t -> x.S);
	out(t -> l, lvl + 1);
	out(t -> r, lvl + 1);
}

void remove(pitem & t, int x, int y) {
	pitem t1, t2, t3;
	split(t, t1, t3, {x, y});
	split(t1, t1, t2, {x, y - 1});
//	puts("---");
//	out(t1);
//	puts("---");
//	out(t2);
//	puts("---");
//	out(t3);
//	puts("---");
	merge(t, t1, t3);
}

char s[10];
int n, x, y;
pitem root;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		scanf("%d%d", &x, &y);
		if (s[1] == 'a') {
			insert(root, x, y);
		}
		if (s[1] == 'f') {
			pitem t1, t2;
			split(root, t1, t2, {x, inf});
			out(t2);
			pitem t = most_left(t2, y);
			if (t)
				printf("%d %d\n", t -> x.F, t -> x.S);
			else
				puts("-1");
			merge(t, t1, t2);
			out(root);
		}
		if (s[1] == 'r') {
			remove(root, x, y);
			out(root);
		}
	}
}
