
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

int n, m;
ll cur;
int x, y;
ll a[505][505];

bool check() {
	set <ll> se;
	ll C = 0, D = 0;
	for (int i = 1; i <= n; i++) {
		ll A = 0, B = 0;
		for (int j = 1; j <= n; j++) {
			A += a[i][j];
			B += a[j][i];
		}
		C += a[i][i];
		D += a[n - i + 1][i];
		se.insert(A);
		se.insert(B);
	}
	se.insert(C);
	se.insert(D);
	return se.size() < 2;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf(I64, &a[i][j]);
			if (!a[i][j])
				x = i, y = j;
		}
	if (n == 1)
		rt("1");
	set <ll> se;
	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		ll X = 0;
		for (int j = 1; j <= n; j++)
			X += a[i][j];
		se.insert(X);
	}
	for (int i = 1; i <= n; i++) {
		if (i == y)
			continue;
		ll X = 0;
		for (int j = 1; j <= n; j++)
			X += a[j][i];
		se.insert(X);
	}
	if (se.size() != 1) {
//		if (n == 7)
//			rt("-2");
		rt("-1");
	}
	ll cur = 0;
	for (int j = 1; j <= n; j++)
		cur += a[x][j];
	a[x][y] = *se.begin() - cur;
	if (a[x][y] <= 0) {
//		if (n == 7) {
//			rt("-3");
//		}
		rt("-1");
	}
	if (!check()) {
//		if (n == 7)
//			rt("-4");
		rt("-1");
	}
	printf(I64, a[x][y]);
}

