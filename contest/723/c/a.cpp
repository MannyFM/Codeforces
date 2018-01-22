
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

int n, m, a[maxn];
int ans;

bool solve() {
	map <int, int> cnt;
	for (int i = 1; i <= n; i++)
		cnt[a[i]]++;
	int mn = inf, x = -1;
	for (int i = 1; i <= m; i++)
		if (umin(mn, cnt[i]))
			x = i;
	int need = n / m;
	if (mn >= need)
		return 0;
	ans++;
	int mx = -inf, y = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > m)
			if (umax(mx, cnt[a[i]]))
				y = i;
	}
	if (y == -1)
		for (int i = 1; i <= n; i++)
			if (cnt[a[i]] > need && umax(mx, cnt[a[i]]))
				y = i;

	a[y] = x;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
	return 1;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int mx = n / m;
	while (solve());
	printf("%d %d\n", mx, ans);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}
