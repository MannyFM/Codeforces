
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

int n, m, a[maxn], b[maxn];
int ex;

int f(int l)
{
	ll extra = 0;
	for (int i = 1; i <= l; i++)
		extra += max(0, b[l - i + 1] - a[i]);
//	printf("f(%d)=" I64 "\n", l, extra);
	return extra;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &ex);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	reverse(a + 1, a + 1 + n);
	int l = -1, r = min(n, m) + 1;
	while (r - l > 1)
	{
		int md = l + (r - l) / 2;
		if (f(md) <= ex)
			l = md;
		else
			r = md;
	}
	ll ans = 0;
	for (int i = 1; i <= l; i++)
		ans += b[i];
	printf("%d " I64, l, max(0ll, ans - ex));
}

