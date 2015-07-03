
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n, k;
int ans, sz, x;
int a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int t = 1; t <= k; t++)
	{
		scanf("%d", &sz);
		for (int i = 0; i < sz; i++)
			scanf("%d", &a[i]);
		a[sz] = 0;
		if (a[0] == 1)
		{
			int len = 0;
			while (len + 1 < sz && a[len] + 1 == a[len + 1])
				len++;
			ans += n + sz - 2 * len - 2;
		}
		else
			ans += sz - 1;
	}
	printf("%d\n", ans);
}
