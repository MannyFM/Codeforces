
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
#define fn "numbers"

ll a, b, c, d;

ll bp(ll x, ll a)
{
	ll y = 1;
	while (a)
	{
		if (a & 1)
			y *= x;
		x *= x;
		a >>= 1;
	}
	return y;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64 I64 I64 I64, &a, &b, &c, &d);
	vector <ll> v;
	for (ll x = 1; x <= 3; x++)
	{
		ll res = bp(a, x) + bp(b, x) + bp(c, x);
		if (res == d)
			v.pb(x);
	}
	if (v.size() != 1)
		puts("-1");
	else
		printf(I64, v[0]);
}
