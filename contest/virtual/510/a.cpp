
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"

int n, m;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
		{
			for (int j = 0; j < m; j++)
				putchar('#');
			puts("");
			continue;
		}
		if (i % 4 == 2)
		{
			for (int j = 1; j < m; j++)
				putchar('.');
			printf("#\n");
		}
		else
		{
			putchar('#');
			for (int j = 1; j < m; j++)
				putchar('.');
			printf("\n");
		}

	}
}