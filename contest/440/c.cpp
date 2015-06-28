
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
//#define fn "a"
#define F first
#define S second

int ans = inf;

void dfs(ll x, int v)
{
	if (!x)
	{
		ans = min(ans, v);
		return;
	}
	if (v > ans)
		return;
	ll now = 1;
	int k = 1;
	while(now * 10 + 1 <= x)
	{
		now = now * 10 + 1;
		k++;
	}
	dfs(x % now, v + (x / now) * k);
	dfs(now * 10 + 1 - x, v + 1 + k);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	ll x;
	scanf("%I64d", &x);
	dfs(x, 0);
	printf("%d", ans);
}