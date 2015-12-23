
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

int n, m;
int a[maxn][maxn], b[maxn * maxn], sz;

int f(int x1, int y1, int x, int y)
{
	sz = 0;	
	for (int i = x1; i <= x; i++)
		for (int j = y1; j <= y; j++)
			b[++sz] = a[i][j];
	sort(b + 1, b + 1 + sz);
	for (int i = 1; i <= sz; i++)
		printf("%d ", b[i]);
	puts("");
	return b[sz / 2 + 1];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int q, x, y, x1, y1;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d%d", &x1, &x, &y1, &y);
		printf("%d\n", f(x1, y1, x, y));
	}
}

