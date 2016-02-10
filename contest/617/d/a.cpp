
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

int x[4], y[4], ans = 3;

bool is(int x, int l, int r)
{
	return min(l, r) <= x && x <= max(l, r);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 1; i <= 3; i++)
		scanf("%d%d", x + i, y + i);
	if ((x[1] == x[2] && x[2] == x[3]) || (y[1] == y[2] && y[2] == y[3]))
	{
		puts("1");
		return 0;
	}
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
			{
				if (i == j || i == k || j == k)
					continue;
				if ((x[i] == x[k] || x[j] == x[k]) && is(y[k], y[i], y[j]))
					ans = 2;
				if ((y[i] == y[k] || y[j] == y[k]) && is(x[k], x[i], x[j]))
					ans = 2;
			}
	printf("%d", ans);
}

