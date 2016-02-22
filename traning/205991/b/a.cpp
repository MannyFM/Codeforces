
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

int a[maxn], n;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	char c;
	while (scanf("%c", &c) == 1 && '0' <= c && c <= '9')
	{
		a[++n] = c - '0';
		if (a[n] % 8 == 0)
		{
			printf("YES\n%d", a[n]);
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int x = 10 * a[i] + a[j];
			if (x % 8 == 0)
			{
				printf("YES\n%d", x);
				return 0;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
			{
				int x = (10 * a[i] + a[j]) * 10 + a[k];
				if (x % 8 == 0)
				{
					printf("YES\n%d", x);
					return 0;
				}
			}
	puts("NO");
}

