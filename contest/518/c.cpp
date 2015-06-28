
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define F first
#define S second
//#define LOCAL

int n, a[maxn], k, b[maxn], m;
int pos[maxn];
//(1 2 3) (4 5 6) (7 8)
//(0 1 2) (3 4 5) (6 7)

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), pos[a[i]] = i;
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	ll ans = 0;
	for (int i = 0; i < m; i++)
	{
		int cur = pos[b[i]];
		if (!cur)
		{
			ans++;
			continue;
		}
		swap(a[cur], a[cur - 1]);
		pos[a[cur]] = cur;
		pos[a[cur - 1]] = cur - 1;
		ans += cur / k + 1;
		//printf("%d %d\n", cur, cur / k + 1);
	}
	printf("%I64d", ans);
}