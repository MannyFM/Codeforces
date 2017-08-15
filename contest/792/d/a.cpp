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

ll n, LVL;

ll size(int lvl) {
	return (1ll << (LVL - lvl)) - 1;
}

char s[maxn];
deque <char> st;
vector <int> pr;

void find(ll v, ll x, ll add = 0) {
	pr.pb(v + add);
	if (v == x)
		return;
	if (x < v)
		find(v / 2, x, add);
	else
		find(v / 2, x - v, add + v);
}

ll go(ll v, ll add = 0) {
	if (st.empty() || v == 1)
		return v + add;
	char g = st.front(); st.pop_front();
	if (g == 'L')
		return go(v / 2, add);
	return go(v / 2, add + v);
}

void solve() {
	ll v;
	int S;
	st.clear();
	pr.clear();

	scanf(I64, &v);
	scanf("%s", s + 1);
	S = strlen(s + 1);
	int ups = 0;
	for (int i = 1; i <= S; i++) {
		if (s[i] == 'U') {
			if (!st.empty())
				st.pop_back();
			else
				ups++;
		} else
			st.push_back(s[i]);
	}

	find((n + 1) / 2, v);
	reverse(all(pr));
//	for (ll x : pr)
//		printf(I64 " ", x);
//	puts("");
//	printf("%d\n", ups);
	ups = min(ups, (int)pr.size() - 1);
	v = pr[ups];
	int lvl = ((int)pr.size() - ups - 1);
//	printf("l %d,", lvl);
	ll to = 1ll << (LVL - lvl - 1);
//	printf("to " I64 ", ", to);
	ll add = v - to;

//	puts("");
	ll ans = go(to) + add;
	printf(I64 "\n", ans);
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf(I64, &n);
	ll tmp = n;
	while (tmp > 0)
		tmp >>= 1, LVL++;
//	printf(I64 "\n", LVL);
//	for (int i = 1; i <= LVL; i++)
//		printf(I64 " ", size(i));
	int q;
	scanf("%d", &q);
	while (q--)
		solve();
}

