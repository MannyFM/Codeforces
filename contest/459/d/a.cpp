
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(1e6 + 12);
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

void upd(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r)
		+ get(v + v + 1, tm + 1, tr, l, r);
}

int n, a[maxn];
int pre[maxn], suf[maxn];
int all[maxn];

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		all[i] = a[i];
	}
	sort(all + 1, all + n + 1);
	int unicorn = unique(all + 1, all + n + 1) - all; // ������ m - ����� ��������� ���������
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(all + 1, all + unicorn, a[i]) - all;

//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
	for (int i = n; i > 0; i--) {
		suf[a[i]]++;
		upd(1, 1, n, suf[a[i]], 1);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		upd(1, 1, n, suf[a[i]], -1);
		suf[a[i]]--;
		pre[a[i]]++;
		ans += get(1, 1, n, 1, pre[a[i]] - 1);
	}
	printf(I64, ans);
}
