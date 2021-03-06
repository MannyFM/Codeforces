
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 505;
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

#define get(a, x1, y1, x2, y2) (a[x1 - 1][y1 - 1] + a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1])

char s[maxn][maxn];
int n, m;
int a[maxn][maxn], ver[maxn][maxn], hor[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[i][j] == '.';
			ver[i][j] = (a[i][j] && a[i - 1][j]) - ver[i - 1][j - 1] + ver[i - 1][j] + ver[i][j - 1];
			hor[i][j] = (a[i][j] && a[i][j - 1]) - hor[i - 1][j - 1] + hor[i - 1][j] + hor[i][j - 1];
		}
	int m, r1, c1, r2, c2;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		printf("%d\n", get(ver, r1 + 1, c1, r2, c2) + get(hor, r1, c1 + 1, r2, c2));
	}
}

