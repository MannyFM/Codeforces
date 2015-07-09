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
//#define fn ""

ll r, g, b;

template <typename T>
T min(T a, T b, T c)
{
	return min(min(a, b), c);
}

template <typename T>
T max(T a, T b, T c)
{
	return max(max(a, b), c);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64 I64 I64, &r, &g, &b);
	if (max(r, g, b) >= 2 * (r + g + b - max(r, g, b)))
		printf(I64, r + g + b - max(r, g, b));
	else
		printf(I64 , (r + g + b) / 3);
}
