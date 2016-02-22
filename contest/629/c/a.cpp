
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

int n, m;
char s[maxn];
int p, q;
ll dp[2050][4050];
int shift = 2010;

ll rec(int len, int bal)
{
	if (abs(bal) > len)
		return 0;
	if (!len)
		return !bal;
	ll & ans = dp[len][bal + shift];
	if (ans != -1)
		return ans;
	ans = rec(len - 1, bal - 1) + rec(len - 1, bal + 1);
	if (ans >= inf)
		ans -= inf;
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int bal = 0;
	for (int i = 1; i <= m; i++)
	{
		if (s[i] == '(')
			bal++;
		if (s[i] == ')')
			bal--;
		umin(p, bal);
	}
	memset(dp, -1, sizeof(dp));
	int N = n - m;
	ll ans = 0ll;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
			if (p + j >= 0)
			{
				ans = (ans + rec(i, j) * rec(N - i, bal + j)) % inf;
			}
	}
	printf(I64, ans);
}

