
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
#define F first
#define S second
//#define fn ""

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif	

int n;
vector <int> v;
ll ans = 0;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int sz = 0;
	int x = n;
	while (x > 0)
		x /= 10, sz++;
	int dec = 1;
	ans = sz * 1ll * (n + 1);
	for (int i = 0; i < sz; i++)
		ans -= dec, dec *= 10;
	printf(I64, ans);
}
