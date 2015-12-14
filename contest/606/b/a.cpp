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

int n, m, x, y, l, cnt;
char s[maxn];
bool was[550][550];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &x, &y);
	scanf("%s", s + 1);
	l = strlen(s + 1);
	printf("%d ", 1);
	was[x][y] = 1;
	for (int i = 1; i < l; i++)
	{
		if (s[i] == 'U' && x != 1)
			x--;
		if (s[i] == 'D' && x != n)
			x++;
		if (s[i] == 'R' && y != m)
			y++;
		if (s[i] == 'L' && y != 1)
			y--;
		printf("%d ", !was[x][y]);
		//printf("= %d %d %c\n", x, y, s[i]);
		was[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt += !was[i][j];
	printf("%d", cnt);
}
