
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

int n, x, ans, a[maxn], b[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	reverse(a + 1, a + 1 + n);
	reverse(b + 1, b + 1 + n);
	int j = n, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		while (j > 0 && a[i] + b[j] < x)
			j--;
		if (j <= 0)
			break;
		ans++;
		j--;
	}
	int res = 0;
	j = n;
	for (int i = 1; i <= n; i++)
	{
		while (j > 0 && a[j] + b[i] < x)
			j--;
		if (j <= 0)
			break;
		res++;
		j--;
	}
	printf("1 %d", max(ans, res));
}

