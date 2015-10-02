
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
#define fn "fenwick"

int t[maxn][maxn];
int n;

int sum (int x, int y)
{
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			result += t[i][j];
	return result;
}

void upd(int x, int y)
{
	for (int i = x; i < n; i = (i | (i + 1)))
		for (int j = y; j < n; j = (j | (j + 1)))
			t[i][j]++;
}

int sum(int xl, int yl, int xr, int yr)
{
	return sum(xr, yr) + sum(xl - 1, yl - 1) - sum(xr, yl - 1) - sum(xl - 1, yr);
}

char s[5];

int main()
{
	#ifdef fn       	
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int M;
	scanf("%d%d", &n, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", s);
		if (s[0] == 'A')
		{
			int X, Y;
			scanf("%d%d", &X, &Y);
			X--, Y--;
			upd(X, Y);
		}
		else
		{
			int xl, xr, yl, yr;
			scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
			xl--, yl--, xr--, yr--;
			printf("%d\n", sum(min(xl, xr), min(yl, yr), max(xl, xr), max(yl, yr)));
		}
	}
}
