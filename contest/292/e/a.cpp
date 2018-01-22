
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

int t[4 * maxn];

void push(int v, int tl, int tr) {
	if (tl == tr || t[v] == -1)
		return;
	t[v + v] = t[v + v + 1] = t[v];
	t[v] = -1;
}

void build(int v, int tl, int tr) {
	t[v] = -1;
	if (tl == tr) {
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r) {
		t[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
}

int get(int v, int tl, int tr, int pos) {
	push(v, tl, tr);
	if (tl == tr) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return get(v + v, tl, tm, pos);
	else
		return get(v + v + 1, tm + 1, tr, pos);
}

int n, a[maxn], b[maxn];
int x[maxn], y[maxn], k[maxn], m;

int solve(int j) {
	int id  = get(1, 1, n, j);
	if (id == -1)
		return b[j];
	int pos = (j - y[id] + x[id]);
	return a[pos];
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int p, pos;
		scanf("%d", &p);
		if (p == 1) {
			scanf("%d%d%d", x + i, y + i, k + i);
			upd(1, 1, n, y[i], y[i] + k[i] - 1, i);
		}
		if (p == 2) {
			scanf("%d", &pos);
			printf("%d\n", solve(pos));
		}
	}
}
