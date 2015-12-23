
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

ll G(int len)
{
	if (len == 1)
		return 45;
	if (len == 2)
		return 495;
	ll ans = 0;
	ll x = 1ll;
	for (int i = 2; i <= len; i++)
		x = x * 10;
	x++;
	x *= 45;
}

ll f(int x)
{
	vector <int> v;
	int X = x;
	while (X > 0)
	{
		v.pb(X % 10);
		X /= 10;
	}
	reverse(v.begin(), v.end());
	int l = v[0], r = v.back(), len = v.size(), mid = 0;
	for (int i = 1; i + 1 < len; i++)
		mid = mid * 10 + v[i];
	ll ans = 0ll;
	for (int i = 1; i < len; i++)
		ans += G(i);
	int u = min(l, r);
	for (int i = 1; i < u; i++)

}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int l, r;
	scanf("%d%d", &l, &r);
	printf(I64, f(r) - f(l - 1));
}

