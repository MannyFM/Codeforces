
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
#define fn "a"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

int n, m, a[200][200];

bool equal(int h)
{
	if (n % h)
		return 0;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 2; j <= n / h; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				int y = (j - 1) * h;
				if (j % 2 == 0)
					y += h - i + 1;
				else
					y += i;
				if (a[i][k] != a[y][k])
					return 0;
			}
		} 
	}
	return 1;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	vector <int> v;
	int k = n;
	v.pb(n);
	while (k % 2 == 0)
		k /= 2, v.pb(k);
	sort(begin(v), end(v));
	for (auto h : v)
	{
		if (equal(h))
		{
			printf("%d", h);
			return 0;
		}
	}
	printf("%d", n);
}