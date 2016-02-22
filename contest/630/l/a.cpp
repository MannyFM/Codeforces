
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

ll bp(ll a, ll b, ll c)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans * a) % c;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	return ans;
}

int s[6];
int a[6], b[] = {0, 1, 3, 5, 4, 2};

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int y;
	scanf("%d", &y);
	for (int i = 5; i > 0; i--)
	{
		s[i] = y % 10;
		y /= 10;
	}
	int x = 0;
	for (int i = 1; i < 6; i++)
	{
		a[i] = s[b[i]];
		x = x * 10 + a[i];
	}
//	printf("%d\n", x);
	printf("%05I64d", bp(x, 5, 100000));
}

