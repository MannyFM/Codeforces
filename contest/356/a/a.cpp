
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(3e5 + 12);
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
#define fill MyLittleFill
#define rt(x)                                                                  \
  {                                                                            \
    puts(x);                                                                   \
    exit(0);                                                                   \
  }
//#define fn ""

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int fill[4 * maxn];

void build(int v, int tl, int tr) {
	if (tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	fill[v] = -1;
}

void push(int v, int tl, int tr) {
	if (fill[v] == -1 || tl == tr)
		return;
	fill[v + v] = fill[v];
	fill[v + v + 1] = fill[v];
	fill[v] = -1;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l)
		return;
	if (l <= tl && tr <= r) {
		fill[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
}

void output(int v, int tl, int tr) {
	push(v, tl, tr);
	if (tl == tr) {
		printf("%d ", fill[v]);
		return;
	}
	int tm = (tl + tr) >> 1;
	output(v + v, tl, tm);
	output(v + v + 1, tm + 1, tr);
}

int n, m;
int l[maxn], r[maxn], x[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", l + i, r + i, x + i);
	}
	for (int i = m; i > 0; i--) {
		upd(1, 1, n, l[i], x[i] - 1, x[i]);
		upd(1, 1, n, x[i] + 1, r[i], x[i]);
	}
	output(1, 1, n);
	puts("");
}
