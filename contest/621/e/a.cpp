
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
#define fn "a"

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

int n, b, k, x, a[maxn];

struct mt
{
	ll a[110][110], b[110][110];
	void const operator *= (const mt & c)
	{
		for (int i = 0; i < x; i++)
			for (int j = 0; j < x; j++)
			{
				b[i][j] = 0;
				for (int k = 0; k < x; k++)
					b[i][j] = (b[i][j] + a[i][k] * c.a[k][j]) % inf;
			}
		for (int i = 0; i < x; i++)
			for (int j = 0; j < x; j++)
				a[i][j] = b[i][j];
	}
} d, ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &b, &k, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j <= n; j++)
			d.a[i][(i * 10 + a[j]) % x]++;
		ans.a[i][i] = 1;
	}
	while (b)
	{
		if (b & 1)
			ans *= d;
		d *= d;
		b >>= 1;
	}
	printf(I64, ans.a[0][k]);
}

