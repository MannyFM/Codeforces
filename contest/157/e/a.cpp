
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

int dp[102][102 * 26 + 2];
int T, sum, n;
char s[120];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	dp[0][0] = 1;
	for (int i = 0; i <= 100; i++)
		for (int sum = 0; sum <= i * 26; sum++)
		{
			if (dp[i][sum])
				for (int k = 0; k < 26; k++)
					dp[i + 1][sum + k] = (dp[i + 1][sum + k] + dp[i][sum]) % inf;
		}
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%s", s);
		n = strlen(s);
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += s[i] - 'a';
		printf("%d\n", dp[n][sum] - 1);
	}
}

