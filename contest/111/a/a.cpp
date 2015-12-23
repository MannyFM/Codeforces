
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

int n;
ll x, y, s;
vector <int> v;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d" I64 I64, &n, &x, &y);
	if (n > y)
	{
		puts("-1");
		return 0;
	}
	s = n - 1 + (y - n + 1ll) * (y - n + 1ll);
	if (s < x)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i < n; i++)
		printf("1\n");
	printf(I64, y - n + 1);
}
