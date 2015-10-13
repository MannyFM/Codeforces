
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maan = int(1e5 + 12);
int const maab = int(2e6 + 12);
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
#define neat MyLittleNeat
//#define end MyLittleEnd
#define all(a) a.begin(), a.end()
//#define fn ""

ll a, b;
vector <pair <int, char>> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64 I64, &a, &b);
	if (__gcd(a, b) != 1)
	{
		puts("Impossible");
		return 0;
	}
	bool step = 0;
	while (a && b)
	{
		//printf(I64 " " I64 "\n", a, b);
		if (v.empty() || v.back().S != step + 'A')
		{
			if (a / b > 0)
				v.pb(mp(a / b, step + 'A'));
		}
		else
			v.back().F += max(a / b, 0ll);
		step ^= 1;
		a %= b;
		swap(a, b);
	}
	v.back().F--;
	if (!v.back().F)
		v.pop_back();
	reverse(all(v));
	for (auto a : v)
		printf("%d%c", a.F, a.S);
	
}
