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

int const maxn = 150 * 1000 + 10;
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
	item *l, *r;
	int val;
	item () : l(0), r(0), val(0) {}
	item(int x) : l(0), r(0), val(x) {}
	item(item * l, item * r, int x) : l(l), r(r), val(x) {}
};

typedef item * pitem;
//vector <item> all;

struct D {
	int sz;
	pitem head, tail;
	D() {
		head = tail = 0;
	}
	void push_front(int x) {
		pitem it = new item(0, head, x);
		head = it;
		if (it -> r)
			it -> r -> l = it;
		if (!sz)
			tail = it;
		sz++;
	}
	void push_back(int x) {
		pitem it = new item(tail, 0, x);
		tail = it;
		if (it -> l)
			it -> l -> r = it;
		if (!sz)
			head = it;
		sz++;
	}
	int pop_front() {
		assert(head);
		pitem it = head;
		head = it -> r;
		if (it -> r)
			it -> r -> l = 0;
		sz--;
		if (!sz)
			tail = 0;
		int ans = it -> val;
		delete it;
		return ans;
	}
	int pop_back() {
		assert(tail);
		pitem it = tail;
		tail = it -> l;
		if (it -> l)
			it -> l -> r = 0;
		sz--;
		if (!sz)
			head = 0;
		int ans = it -> val;
		delete it;
		return ans;
	}
};

D * a[maxn];
//int l = maxn, r = maxn;
char s[100];
int x, y, n;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s %d", s, &x);
		if (s[4] == 'f') {
			scanf("%d", &y);
			if (!a[x])
				a[x] = new D();
			a[x] -> push_front(y);
		}
		if (s[4] == 'b') {
			scanf("%d", &y);
			if (!a[x])
				a[x] = new D();
			a[x] -> push_back(y);
		}
		if (s[3] == 'f') {
			assert(a[x]);
			printf("%d\n", a[x] -> pop_front());
		}
		if (s[3] == 'b') {
			assert(a[x]);
			printf("%d\n", a[x] -> pop_back());
		}
	}
}
