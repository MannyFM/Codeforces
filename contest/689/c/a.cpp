
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

ll m;

int f(ll n) {
	ll ans = 0;
	int k = 2;
	while (k * 1ll * k * k <= n) {
		ans += n / (k * 1ll * k * k);
		if (ans > m)
			return 1;
		k++;
	}
	if (ans == m)
		return 2;
	return ans >= m;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	ll L = 0, R = linf;
	scanf(I64, &m);
	while (R - L > 1) {
		ll mid = (L + R) >> 1;
		if (f(mid))
			R = mid;
		else
			L = mid;
	}
	if (f(L) == 2) {
		printf(I64, L);
		return 0;
	}
	if (f(R) == 2) {
		printf(I64, R);
		return 0;
	}
	puts("-1");

}

