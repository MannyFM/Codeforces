
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

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
#define rt(x) {puts(x); exit(0);}
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int X, Y;
int a[4];
int ans;

int solve(int y) {
	a[1] = y;
	a[2] = X;
	a[3] = X;

	ans = 1;
	while (a[3] != Y) {
		ans++;
		a[3] = a[2];
		a[2] = max(a[3] - a[1] + 1, Y);
		sort(a, a + 3);
//		printf("%d %d %d\n", a[1], a[2], a[3]);
	}
//	printf("%d", ans);
	return ans;
}

map <int, vector <int> > m;
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &X, &Y);
	if (X == Y)
		rt("0");
	int ans = -1, mn = inf;
	for (int k = Y; k < X; k++) {
		int cur = solve(k);
		//printf("f(%d)=%d\n", k, cur);
		m[cur].pb(k);
	}
	for (int x : m.begin() -> S)
		printf("f[%d]=%d\n", x, m.begin() -> F);
}

