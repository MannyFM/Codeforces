
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 150;
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

int n, a[maxn];
bool us[maxn];
int now = inf, ans = 1;

int find(int x)
{
	int i = 1;
	while (i <= n && a[i] < x)
		i++;
	return i == 1 ? n + 1 : i - 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int cnt = n;
	while (cnt)
	{
		if (!now)
		{
			puts("");
			now = inf;
			ans++;
			continue;
		}
		int v = find(now);
		printf("!%d!", v);
		if (v == n + 1)
		{
			v = find(now + 1);
			printf("@%d@", v);
		}
		if (v == n + 1)
		{
			puts("");
			now = inf;
			ans++;
			continue;
		}
		now = min(now - 1, a[v]);
		printf("%d (%d) ", a[v], now);
		us[v]++;
		cnt--;
	}
	puts("");
	printf("%d", ans);
}
