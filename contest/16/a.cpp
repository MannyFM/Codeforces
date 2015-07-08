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
//#define fn ""

int n, m;
char s[110][110];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("\n%s", s[i]);
	for (int i = 0; i < n; i++)
	{
		if (s[i][0] == s[i + 1][0])
		{
			puts("NO");
			return 0;
		}
		for (int j = 1; j < m; j++)
			if (s[i][j] != s[i][j - 1])
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
}
