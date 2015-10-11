#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 550;
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
#define S scond
//#define fn ""

int n;
ll g[maxn * maxn];
ll a[maxn];
multiset <ll> s;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int nn = n * n;
	for (int i = 1; i <= nn; i++)
	{
		scanf(I64, g + i);
		s.insert(-g[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = -(*s.begin());
		//printf("%d ", a[i]);
		s.erase(s.begin());
		for (int j = 1; j < i; j++)
		{
			s.erase(s.find(-__gcd(a[j], a[i])));
			s.erase(s.find(-__gcd(a[j], a[i])));
		}
	}
	for (int i = 1; i <= n; i++)
		printf(I64 " ", a[i]);
}
