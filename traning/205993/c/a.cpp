
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

int n, l, r, x;
int c[16];
int ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", c + i);
	for (int mask = 1; mask < (1 << n); mask++)
	{
		if (__builtin_popcount(mask) < 2)
			continue;
		int mn = inf, mx = -inf, sum = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
			{
				umin(mn, c[i]);
				umax(mx, c[i]);
				sum += c[i];
			}
		ans += l <= sum && sum <= r && (mx - mn) >= x;
	}
	printf("%d", ans);
}

