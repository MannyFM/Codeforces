
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
//#define fn

ll dp[25][3];
int n;

ll rec(int pos, int last)
{
	if (pos == n)
		return 1;
	ll & ans = dp[pos][last];
	if (ans != -1)
		return ans;
	ans = rec(pos + 1, 1);
	if (last != 1)
		ans += rec(pos + 1, 0);
	ans += rec(pos + 1, 0);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	memset(dp, -1ll, sizeof(dp));
	printf(I64, rec(0, 0));
}
