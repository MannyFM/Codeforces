
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

int a[maxn], b[maxn], n;
ll p[maxn], s[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] + a[i];
		s[i] = s[i - 1] + b[i];
	}
	int m, l, r, t;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1)
			printf(I64 "\n", p[r] - p[l - 1]);
		else
			printf(I64 "\n", s[r] - s[l - 1]);
	}
}

