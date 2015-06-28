
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
//#define fn "a"
#define F first
#define S second

map <int, int> pos;
int n, x[maxn];
int d;
ll ans;

ll calc(ll x)
{
	return x > 0 ? x * (x + 1ll) / 2 : 0;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", x + i), pos[x[i]] = i;
	int r = 2;
	for (int i = 1; i < n - 1; i++)
	{
		while (r <= n && x[i] + d >= x[r])
			r++;
		ans += calc(r - i - 2);
	}	
	printf("%I64d", ans);
}
