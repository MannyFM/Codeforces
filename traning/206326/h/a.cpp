
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

int n, k, a, m;
int x[maxn];

inline int cnt(int l)
{
//	printf("cnt(%d)=%d\n", l, (l + 1) / (a + 1));
	return (l + 1) / (a + 1);
}

int f(int l)
{
	vector <int> v = {0, n + 1};
	for (int i = 1; i <= l; i++)
		v.pb(x[i]);
	sort(all(v));
	int res = 0;
	for (int i = 1; i < (int)v.size(); i++)
		res += cnt(v[i] - v[i - 1] - 1);
//	printf("f(%d)=%d\n", l, res);
	return res;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &k, &a);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", x + i);
	int l = 0, r = m + 1;
	while (r - l > 1)
	{
//		printf("[%d %d]\n", l, r);
		int m = l + (r - l) / 2;
		if (f(m) < k)
			r = m;
		else
			l = m;
	}
	printf("%d\n", r == m + 1 ? -1 : r);
}

