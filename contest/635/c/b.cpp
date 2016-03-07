
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

ll solve(ll s, ll x)
{
	if (s < x)
		return 0ll;
	bool same = s == x;
	int num = 0;
	while (s > 0 || x > 0)
	{
		printf("[" I64 " " I64 "]\n", s, x);
		if (s < 0)
			return 0ll;
		if (s % 2 != x % 2)
			return 0ll;
		if (x % 2 == 1)
		{
			num++;
			x /= 2;
			s /= 2;
		}
		else
		{
			ll ns = s / 2, nx = x / 2;
			if (ns % 2 == nx)
			{
				s /= 2, x /= 2;
			}
			else
			{
				s /= 2, x /= 2;
				s--;
			}
		}
	}
	ll res = 1ll;
	while (num)
	{
		res *= 2;
		num--;
	}
	if (same)
		res -= 2;
	return res;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	ll x, s;
	scanf(I64 " " I64, &s, &x);
	printf(I64, solve(s, x));
}

