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

int n, a[maxn];
char s[maxn];
bool del[maxn];
vector <int> cnt[4];

int solve(int one, int two) {
	memset(del, 0, sizeof(del));
	int ans = 0;
	if ((int)cnt[1].size() < one)
		return inf;
	if ((int)cnt[2].size() < two)
		return inf;
	ans = one + two;
	memset(del, 0, sizeof(del));
	for (int x = 0; x < one; x++)
		del[cnt[1][x]] = 1;
	for (int x = 0; x < two; x++)
		del[cnt[2][x]] = 1;
	for (int i = 1; i <= n; i++) {
		if (del[i])
			continue;
		if (a[i] > 0)
			break;
//		printf("[%d] ", i);
		ans++;
		if (ans == n)
			return ans - 1;
		del[i] = 1;
	}
//	printf("%d %d = %d\n", one, two, ans);
	if (ans >= n)
		return inf;
	return ans;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int need = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
		cnt[a[i] % 3].pb(i);
		need = (need + a[i]) % 3;
	}
	reverse(all(cnt[1]));
	reverse(all(cnt[2]));
	int ans = inf;
	int x = -1, y = -1;
	for (int one = 0; one < 3; one++)
		for (int two = 0; two < 3; two++) {
			if ((one + two * 2) % 3 != need)
				continue;
			if (umin(ans, solve(one, two)))
				x = one, y = two;
		}
	if (ans >= inf)
		rt("-1");
	solve(x, y);
//	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (!del[i])
			printf("%d", a[i]);
}

