
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

int n, t;
int ng = -1;
int dp[maxn], a[maxn];
char s[maxn];

int f() {
	for (int i = ng + 1; i <= n; i++)
		if (dp[i] <= t)
			return i;
	return n + 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d %d %s", &n, &t, s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '.')
			ng = i, a[i] = -1;
		else
			a[i] = s[i] - '0';
	}
	dp[n + 1] = inf;
	for (int i = n; i > ng; i--) {
		if (a[i] > 4)
			dp[i] = 1;
		if (a[i] == 4)
			dp[i] = dp[i + 1] + 1;
		if (a[i] < 4)
			dp[i] = inf;
	}
	int pos = f();
//	printf("%d\n", pos);
	if (pos != n + 1) {
		pos--;
		int ok = 1;
		for (int i = pos; i > 0; i--) {
			if (a[i] == -1)
				continue;
			a[i] += ok;
			ok = a[i] / 10;
			a[i] %= 10;
			if (!ok)
				break;
		}
		if (ok)
			printf("1");
		n = pos;
	}
	if (n == ng)
		n--;
	for (int i = 1; i <= n; i++)
		putchar(a[i] == -1 ? '.' : a[i] + '0');
}

