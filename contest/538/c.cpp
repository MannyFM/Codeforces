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
#define ans(s) ANS = max(ANS, s)
//#define fn ""

int n, m;
int d[maxn], h[maxn];
int ANS = -inf;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", d + i, h + i);
		ans(h[i]);
		if (i == 1)
		{
			if (d[i] > 1)
				ans(h[i] + d[i] - 1);
		}
		if (i == m && d[i] < n)
		{
			ans(h[i] + (n - d[i]));
		}
		if (i > 1)
		{
			int delta = abs(h[i] - h[i - 1]);
			if (delta > d[i] - d[i - 1])
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			int left = d[i] - d[i - 1] - delta;
			left = (left / 2);
			ans(max(h[i], h[i - 1]) + left);
		}
		//printf("%d\n", ANS);
	}
	printf("%d\n", ANS);
}
