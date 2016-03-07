
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

int n, m, cnt[30][maxn];
int a[maxn], l[maxn], r[maxn], x[maxn];
int s[20][maxn], lg[maxn];

int get(int l, int r)
{
	int k = lg[r - l + 1];
	return s[k][l] & s[k][r - (1 << k) + 1];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", l + i, r + i, x + i);
		for (int j = 0; j < 30; j++)
			if (x[i] & (1 << j))
				cnt[j][l[i]]++, cnt[j][r[i] + 1]--;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 30; j++)
		{
			cnt[j][i] += cnt[j][i - 1];
			a[i] |= (1 << j) * (cnt[j][i] > 0);
		}
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= n; i++)
		s[0][i] = a[i];
	for (int k = 1; k <= lg[n]; k++)
		for (int i = 1; i <= n; i++)
			s[k][i] = s[k - 1][i] & s[k - 1][i + (1 << (k - 1))];
	for (int i = 1; i <= m; i++)
		if (get(l[i], r[i]) != x[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);	
}

