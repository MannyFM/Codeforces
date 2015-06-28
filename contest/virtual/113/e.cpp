
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e7 + 12)
#define inf int(1e9 + 7)
#define mod int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"
#define D 1
#define C 2
#define B 3
#define A 4

int n;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	ll lt = 0, ld = 1;
	for (int i = 1; i <= n; i++)
	{
		ll d = (lt * 3) % mod;
		ll t = (lt * 2 + ld) % mod;
		lt = t;
		ld = d;
	}
	printf("%d", int(ld));
}