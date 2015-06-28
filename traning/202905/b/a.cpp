
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

ll calc(ll x)
{
	return x * (x - 1) / 2;
}

ll solve_max(ll n, ll m)
{
	ll k = n - m + 1;
	return calc(k);
}

ll solve_min(ll n, ll m)
{
	ll each = n / m;
	ll carry = n % m;
	//printf("%I64d %I64d\n", each, carry);
	return calc(each + 0ll) * (m - carry) + carry * calc(each + 1);
	
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	printf("%I64d ", solve_min(n, m));
	printf("%I64d ", solve_max(n, m));
}
