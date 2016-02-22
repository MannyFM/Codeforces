
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

int n, m, k;
int a[maxn], l[maxn], r[maxn], d[maxn];
ll b[maxn], cnt[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", l + i, r + i, d + i);
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cnt[x]++, cnt[y + 1]--;
	}
	for (int i = 1; i <= m; i++)
	{
		cnt[i] += cnt[i - 1];
		b[l[i]] += d[i] * 1ll * cnt[i];
		b[r[i] + 1] -= d[i] * 1ll * cnt[i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] += b[i - 1];
		printf(I64 " ", a[i] + b[i]);
	}
}

