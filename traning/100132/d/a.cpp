
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
#define fn "forest"

int n, m, a[110][110], b[110][110];

bool F()
{
	bool ok = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			b[i][j] = a[i][j];
			if (i + 1 <= n && a[i + 1][j] == a[i][j] + 1)
			{
				ok = 1;
				b[i][j]++;
				continue;
			}
			if (j + 1 <= m && a[i][j + 1] == a[i][j] + 1)
			{
				ok = 1;
				b[i][j]++;
				continue;
			}
			if (i >= 2 && a[i - 1][j] == a[i][j] + 1)
			{
				ok = 1;
				b[i][j]++;
				continue;
			}
			if (j >= 2 && a[i][j - 1] == a[i][j] + 1)
			{
				ok = 1;
				b[i][j]++;
				continue;
			}
		}
	return ok;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int ans = 0;
	while (F())
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = b[i][j];
		ans++;
	}
	printf("%d\n", ans);
	for (int i= 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
}
