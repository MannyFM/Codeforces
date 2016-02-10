
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(1e7 + 12);
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

int n, m, a[maxn], b[maxn];
int A[maxb], B[maxb];
int p[maxb];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 2; i * 1ll * i < maxb; i++)
	{
		if (p[i])
			continue;
		for (int j = i * 1ll * i; j < maxb; j += i)
			if (!p[j])
				p[j] = i;
	}
	for (int i = 2; i < maxb; i++)
		if (!p[i])
			p[i] = i;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		while (x > 1)
		{
			A[p[x]]++;
			x /= p[x];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x = b[i];
		while (x > 1)
		{
			B[p[x]]++;
			x /= p[x];
		}
	}
	for (int i = 0; i < maxb; i++)
	{
		 int val = min(A[i], B[i]);
		 A[i] = B[i] = val;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i], val = 1;
		while (x > 1)
		{
			if (A[p[x]])
			{
				A[p[x]]--;
				val *= p[x];
			}
			x /= p[x];
		}
		a[i] /= val;
	}
	for (int i = 1; i <= m; i++)
	{
		int x = b[i], val = 1;
		while (x > 1)
		{
			if (B[p[x]])
			{
				B[p[x]]--;
				val *= p[x];
			}
			x /= p[x];
		}
		b[i] /= val;
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
	for (int i = 1; i <= m; i++)
		printf("%d ", b[i]);
}

