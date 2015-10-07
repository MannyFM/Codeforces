
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5010;
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
#define fn "lesson"

const ll mod = ll(1e9) + 7;

int a[maxn], n;
ll dp[maxn][maxn];
bool up[maxn][maxn], down[maxn][maxn];

ll bp(ll a, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

ll rec(int l, int r)
{
	ll &ans = dp[l][r];
	if (ans != -1)
		return ans;
	if (l == r)
		return ans = 1;
	if (up[l][r] || down[l][r])
		return ans = bp(2, r - l);
	ans = 0ll;
	for (int i = l; i < r; i++)
	if (up[l][i] || down[l][i])
	{
		ll R = rec(i + 1, r);
		//printf("%d %d %d " I64 "\n", l, i, r, R);
		ans = (ans + R) % mod;
	}
	//printf("%d %d " I64 " \n", l, r, rec(l, r));
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int l = 1; l <= n; l++)
	{
		up[l][l] = down[l][l] = 1;
		for (int r = l + 1; r <= n; r++)
		{
			up[l][r] |= (up[l][r - 1]) & (a[r] >= a[r - 1]);
			down[l][r] |= (down[l][r - 1]) & (a[r] <= a[r - 1]);
			/*
			if (!up[l][r] && !down[l][r])
				break;
			*/
			//printf("%d %d %d %d\n", l, r, up[l][r], down[l][r]);
		}
	}
	printf(I64, rec(1, n));
}
