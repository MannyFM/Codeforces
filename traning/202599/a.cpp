
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "floor4"
#define F first
#define S second

set <int> se;
int n;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int i = 1; i <= maxn; i++)
		se.insert(i);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int j;
		scanf("%d", &j);
		if (j > 0)
		{
			auto it = se.lower_bound(j);
			printf("%d\n", *it);
			se.erase(it);
		}
		else
		{
			se.insert(-j);
		}
	}
}