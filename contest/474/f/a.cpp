
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

int gcd(int x, int y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

struct item {
	int g;
	int mn, cnt;
	item() {
		g = 0;
		mn = inf;
		cnt = 0;
	}
	item(int x) {
		g = mn = x;
		cnt = 1;
	}
};

int n, a[maxn];
item t[4 * maxn];

item operator + (const item & a, const item & b) {
	item c;
	if (a.mn != b.mn)
		c = a.mn < b.mn ? a : b;
	else {
		c.mn = a.mn;
		c.cnt = a.cnt + b.cnt;
	}
	c.g = gcd(a.g, b.g);
	return c;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = item(a[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

item get(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || r < tl)
		return item();
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	int m, l, r;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		item ans = get(1, 1, n, l, r);
//		printf("[%d %d]= %d %d %d\n", l, r, ans.g, ans.mn, ans.cnt);
		int cnt = ans.g == ans.mn ? ans.cnt : 0;
		printf("%d\n", r - l + 1 - cnt);
	}
}
