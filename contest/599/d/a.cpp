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

ll a, b, x;
vector <pll> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64, &x);
	x *= 6;
	for (a = 1; a * a * a <= x; a++)
	{
		if (x % a != 0 || x % (a + 1) != 0)
			continue;
		ll b = ((x / a) / (a + 1) + a - 1);
		if (b / 3 < a)
			break;
		if (b % 3)
			continue;
		b /= 3;
		//printf(I64 " " I64 "\n", a, b);
		v.pb(mp(a, b));
		if (a != b)
			v.pb(mp(b, a));
	}
	sort(v.begin(), v.end());
	printf("%d\n" ,v.size());
	for (auto x : v)
		printf(I64 " " I64 "\n", x.F, x.S);
}
