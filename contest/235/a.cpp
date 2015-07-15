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
#define ans(x) ANS = max(ANS, x)
//#define fn ""

ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

inline ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

ll n, ANS;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64, &n);
	for (ll a = max(n - 50, 1ll); a <= n; a++)
	for (ll b = max(n - 50, 1ll); b <= n; b++)
	for (ll c = max(n - 50, 1ll); c <= n; c++)
		ans(lcm(lcm(a, b), c));
	printf(I64, ANS);
}
