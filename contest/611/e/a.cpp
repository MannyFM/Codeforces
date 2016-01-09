
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define fn "E"

int n, d[maxn], y[4];
int dp[10][maxn];

int rec(int pos, int mask)
{
	if (pos == n + 1)
		return 1;
	int & ans = dp[mask][pos];
	if (ans != -1)
		return ans;
	ans = inf;
	int cur = 0;
	if (mask == 7)
		mask = 0, cur = 1;
	for (int i = 1; i < 8; i++)
	{
		int x = 0;
		for (int k = 0; k < 3; k++)
			if (i & (1 << k))
				x += y[k];
		if (x >= d[pos])
		{
			//printf("[%d %d] -> [%d+%d]\n", pos, mask, i, i & mask);
			if (i & mask)
			{
				int z = rec(pos + 1, i) + 2 + cur;
				ans = min(ans, z);
			}
			else
			{
				int z = rec(pos + 1, i | mask) + cur;
				ans = min(ans, z);
			}
		}
	}
	printf("p:%d m:%d a:%d c:%d b:", pos, mask, ans, cur);
	for (int i = 0; i < 3; i++)
		if (mask & (1 << i))
			printf("%d ", i + 1);
	puts("");
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, y, y + 1, y + 2);
	for (int i = 1; i <= n; i++)
		scanf("%d", d + i);
	sort(d + 1, d + 1 + n);
	reverse(d + 1, d + 1 + n);
	memset(dp, -1, sizeof(dp));
	int ans = rec(1, 0);
	if (ans >= inf)
		ans = -1;
	printf("%d", ans);
}

