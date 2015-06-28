
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second

int n, m, c[maxn];
set <int> se[maxn], cl;

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i), cl.insert(c[i]);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (c[a] == c[b])
			continue;
		se[c[a]].insert(c[b]);
		se[c[b]].insert(c[a]);
	}
	int ans = -1;
	for (auto i : cl)
		ans = max(ans, (int)se[i].size());
	for (auto i : cl)
	{
		if (ans == (int)se[i].size())
		{
			printf("%d", i);
			return 0;
		}
	}

}