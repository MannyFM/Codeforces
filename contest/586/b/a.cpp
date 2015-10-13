
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

int n, a[55], b[55], c[55];
int x[55], y[55];

inline int f(int i)
{
	return x[i] + c[i + 1] + y[i + 1];
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d", a + i);
	for (int i = 1; i < n; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i);
	for (int i = 1; i <= n; i++)
		x[i] = x[i - 1] + a[i];
	for (int i = n; i > 0; i--)
		y[i] = y[i + 1] + b[i];
	int d = 0;
	for (int i = 0; i < n; i++)
		if (f(i) < f(d))
			d = i;
	int e = !d;
	for (int i = 0; i < n; i++)
		if (i != d && f(i) < f(e))
			e = i;
	printf("%d", f(d) + f(e));
}
