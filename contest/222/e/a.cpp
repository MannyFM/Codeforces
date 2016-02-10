
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

ll n;
int m, k;

struct matrix
{
	int a[55][55], c[55][55];

	void operator *= (const matrix & b)
	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < m; j++)
//				printf("%d ", a[i][j]);
//			puts("");
//		}
//		puts("\n*");
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < m; j++)
//				printf("%d ", b.a[i][j]);
//			puts("");
//		}
//		puts("\n=");
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < m; k++)
				{
					c[i][j] = (c[i][j] + a[i][k] * 1ll * b.a[k][j]) % inf;
					if (c[i][j] < 0)
						c[i][j] += inf;
				}
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = c[i][j];

//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < m; j++)
//				printf("%d ", a[i][j]);
//			puts("");
//		}
//		puts("\n");
	}
} ans, a;

inline int f(char x)
{
	if ('a' <= x && x <= 'z')
		return x - 'a';
	return x - 'A' + 26;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 "%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a.a[i][j] = 1;
	for (int i = 0; i < k; i++)
	{
		char x, y;
		scanf(" %c%c", &x, &y);
		a.a[f(x)][f(y)] = 0;
	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//			printf("%d ", a.a[i][j]);
//		puts("");
//	}
	for (int i = 0; i < m; i++)
		ans.a[i][i] = 1;
	n--;
	while (n)
	{
		if (n & 1)
		{
//			puts("ans *= a");
			ans *= a;
		}
//		puts("a *= a");
		a *= a;
		n >>= 1;
	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//			printf("%d ", ans.a[i][j]);
//		puts("");
//	}
	ll res = 0ll;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			res = (res + ans.a[i][j]) % inf;
	printf(I64, res);
}

