#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e3 + 12);
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

int n, a[maxn], us[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int cur = 0, cnt = 0, ans = 0;
	while (cnt < n)
	{
		if (ans % 2 == 0)
		{
			for (; cur < n; cur++)
				if (!us[cur] && a[cur] <= cnt)
				{
					cnt++;
					us[cur]++;
				}
			cur--;
		}
		else
		{
			for (; cur >= 0; cur--)
				if (!us[cur] && a[cur] <= cnt)
				{
					cnt++;
					us[cur]++;
				}
			cur++;
		}
		if (cnt < n)
			ans++;
	}
	printf("%d", ans);
}
