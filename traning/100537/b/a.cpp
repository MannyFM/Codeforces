
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

int a[101][101];
int n, m;

bool correct(int i, int j)
{
	set <int> x, y;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
		{
			if (abs(di) + abs(dj) <= 1)
				x.insert(a[i + di][j + dj]);
			if (abs(di) + abs(dj) > 0)
				y.insert(a[i + di][j + dj]);
		}
	return x.size() == 5 && y.size() <= 4;
}

bool check()
{
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++)
			if (!correct(i, j))
				return false;
	return true;
}

bool rec(int i, int j)
{
	if (i == n + 1)
		return check();
	if (j == m + 1)
		return rec(i + 1, 1);
	for (int x = 1; x <= 5; x++)
	{
		a[i][j] = x;
		if (rec(i, j + 1))
			return true;
	}
	return false;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	if (rec(1, 1))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", a[i][j]);
			puts("");
		}
	}
	else
		puts("-1");
}
