
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(1e6 + 12);
int const maxlen = int(1e6 + 12);
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
	item * l, * r;
	int val;
	item() {
		l = r = 0;
		val = 0;
	}
} items[20 * maxlen];
unsigned int items_sz = 0;

typedef item * pitem;

int val(pitem t) {
	return t ? t -> val : 0;
}

void upd(pitem &t, int tl, int tr, int pos, int x) {
	if (!t)
		t = items + (items_sz++);
	if (tl == tr) {
		t -> val += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(t -> l, tl, tm, pos, x);
	else
		upd(t -> r, tm + 1, tr, pos, x);

	t -> val = val(t -> l) + val(t -> r);
}

int get(pitem t, int tl, int tr, int l, int r) {
	if (!t || l > r || tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r)
		return val(t);
	int tm = (tl + tr) >> 1;
	return get(t -> l, tl, tm, l, r)
		+ get(t -> r, tm + 1, tr, l, r);
}

int n, a[maxn], all[maxn];
ll ans;
pitem pre, suf;

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	int L = inf, R = -inf;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		all[i] = a[i];
	}
	sort(all + 1, all + 1 + n);
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(all + 1, all + 1 + n, a[i]) - all;
	for (int i = 1; i <= n; i++) {
		umin(L, a[i]);
		umax(R, a[i]);
//		printf("%d ", a[i]);
	}
//	puts("");
	for (int i = n; i > 0; i--) {
		upd(suf, L, R, a[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		upd(suf, L, R, a[i], -1);
		ll more = get(pre, L, R, a[i] + 1, R);
		ll less = get(suf, L, R, L, a[i] - 1);
		ans += less * 1ll * more;
		upd(pre, L, R, a[i], +1);
	}
	printf(I64, ans);
}
