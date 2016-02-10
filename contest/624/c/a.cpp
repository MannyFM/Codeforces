
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e3 + 12);
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

int n, m;
bool can[maxn][maxn];
vector <int> g[maxn];
int a[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
		can[x][y] = can[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
		if ((int)g[i].size() == n - 1)
			a[i] = 2;
	for (int i = 1; i <= n; i++)
	{
		if (!a[i])
		{
			a[i] = 1;
			for (int j = 1; j <= n; j++)
				if (!a[j] && !can[i][j])
					a[j] = 3;
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%c ", a[i] - 1 + 'a');
//	puts("");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			if ((can[i][j] && abs(a[i] - a[j]) > 1) || (!can[i][j] && abs(a[i] - a[j]) < 2))
			{
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	for (int i = 1; i <= n; i++)
		printf("%c", a[i] - 1 + 'a');

}

