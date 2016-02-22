
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
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

int n, a[maxn];
int l[maxn], r[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	a[0] = -inf;
	a[n + 1] = inf;
	for (int i = 1; i <= n; i++)
		l[i] = (a[i] > a[i - 1] ? l[i - 1] : 0) + 1;
	for (int i = n; i > 0; i--)
		r[i] = (a[i] < a[i + 1] ? r[i + 1] : 0) + 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		umax(ans, l[i] + 1);
		umax(ans, r[i] + 1);
		if (a[i + 1] > a[i - 1] + 1)
			umax(ans, l[i - 1] + 1 + r[i + 1]);
	}
	umin(ans, n);
	printf("%d", ans);
}

