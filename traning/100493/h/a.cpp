
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5012;
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
#define fn "message"

char s[maxn];
int n, k;
int dp[maxn][maxn];

int rec(int l, int r)
{
	//cerr << l << " " << r << '\n';
	int & ans = dp[l][r];
	if (ans != -1)
		return ans;
	ans = inf;
	if (l > r)
		return ans = 0ll;
	if (l == r)
		return ans = 0ll;
	if (s[l] == s[r])
		ans = rec(l + 1, r - 1);
	else
	{
		if (l + 1 <= n)
			ans = min(ans, rec(l + 1, r) + 1);
		if (r >= 2)
			ans = min(ans, rec(l, r - 1) + 1);
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d", &k);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	//printf("%d", rec(1, n));
	int L = 1, R = 1;
	for (int l = 1; l < n; l++)
		for (int r = l + 1; r <= n; r++)
			if (rec(l, r) <= k && R - L < r - l)
			{
				L = l;
				R = r;
			}
	printf("%d %d", L, R);
			
}
