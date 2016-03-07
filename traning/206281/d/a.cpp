
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

char s[maxn];
int cnt[3][maxn], n;

bool get(int l, int r)
{
	if (r - l + 1 < 3)
		return 1;
	int x[] = {cnt[0][r] - cnt[0][l - 1], cnt[1][r] - cnt[1][l - 1], cnt[2][r] - cnt[2][l - 1]};
	sort(x, x + 3);
	return x[2] - x[0] < 2;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[0][i] = cnt[0][i - 1];
		cnt[1][i] = cnt[1][i - 1];
		cnt[2][i] = cnt[2][i - 1];
		cnt[s[i] - 'x'][i]++;
	}
	int m, l, r;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		puts(get(l, r) ? "YES" : "NO");
	}
}

