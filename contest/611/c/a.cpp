
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
//#define fn ""

int n, m, q;
char s[550][550];
int u[550][550], l[550][550];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			u[i][j] = s[i][j] == '.' && s[i - 1][j] == '.';
			u[i][j] += u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
		}
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			l[i][j] = s[i][j] == '.' && s[i][j - 1] == '.';
			l[i][j] += l[i - 1][j] + l[i][j - 1] - l[i - 1][j - 1];
		}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			printf("%d ", u[i][j]);
//		puts("");
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			printf("%d ", l[i][j]);
//		puts("");
//	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int r1, r2, c1, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		c1--;
		int U = u[r1][c1] + u[r2][c2] - u[r1][c2] - u[r2][c1];
		c1++, r1--;
		int L = l[r1][c1] + l[r2][c2] - l[r1][c2] - l[r2][c1];
		r1++;
		printf("%d\n", U + L);
	}
}

