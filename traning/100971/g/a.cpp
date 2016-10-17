
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <ll, ll> mii;
typedef pair <ll, ll> pii;
typedef pair <ll, ll> pll;

ll const maxn = ll(1e5 + 12);
ll const maxlen = ll(2e6 + 12);
ll const inf = ll(1e9 + 7);
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

ll n, m;
ll x1, x2;
ll y1, y2;

bool check(ll n, ll m, ll x1, ll y1, ll x2, ll y2) {
	bool a = (x1 + x2) <= n && max(y1, y2) <= m;
	bool b = (x1 + x2) <= n && max(y1, y2) <= m;
	bool c = (y1 + y2) <= m && max(x1, x2) <= n;
	bool d = (y1 + y2) <= m && max(x1, x2) <= n;
	return a || b || c || d;
}

bool ch(ll x1, ll y1, ll x2, ll y2) {
	return check(n, m, x1, y1, x2, y2) || check(m, n, x1, y1, x2, y2);
}

bool c(ll x2, ll y2) {
	return ch(x1, y1, x2, y2) || ch(y1, x1, x2, y2);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64, &n, &m);
	scanf(I64 I64, &x1, &y1);
	scanf(I64 I64, &x2, &y2);
	if (n * 1ll * m < x1 * 1ll * y1 + x2 * 1ll * y2)
		rt("NO");
	if (c(x2, y2))
		rt("YES");

	if (c(y2, x2))
		rt("YES");

	rt("NO");
}

