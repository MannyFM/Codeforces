
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

ll dp[70][2][2][2][2];
int n, L[70], R[70];

ll rec(int pos, int fl1, int fl2, int fr1, int fr2)
{
	if (pos == n)
		return 0;
	ll & ans = dp[pos][fl1][fl2][fr1][fr2];
	if (ans != -1)
		return ans;
	ans = 0;
	int l0 = 0, l1 = 1;
	int r0 = 0, r1 = 1;
	if (!fl1 && L[pos])
		l0 = 1;
	if (!fl2 && !R[pos])
		l1 = 0;
	if (!fr1 && L[pos])
		r0 = 1;
	if (!fr2 && !R[pos])
		r1 = 0;
//	printf("%d %d %d %d %d\n", pos, fl1, fl2, fr1, fr2);
//	printf("[%d %d] [%d %d]\n", l0, l1, r0, r1);
	for (int i = l0; i <= l1; i++)
	for (int j = r0; j <= r1; j++)
	{
		ll ext = 0ll;
		if (i ^ j)
			ext = 1ll << (n - pos - 1);
		int nfl1 = fl1, nfl2 = fl2, nfr1 = fr1, nfr2 = fr2;
		if (i > L[pos])
			nfl1 = 1;
		if (i < R[pos])
			nfl2 = 1;
		if (j > L[pos])
			nfr1 = 1;
		if (j > R[pos])
			nfr2 = 1;
		umax(ans, ext + rec(pos + 1, nfl1, nfl2, nfr1, nfr2));
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	ll l, r;
	scanf(I64 I64, &l, &r);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 63; i++)
		L[i] = (l & (1ll << i)) > 0;
	for (int i = 0; i < 63; i++)
	{
		R[i] = (r & (1ll << i)) > 0;
		if (R[i])
			n = i + 1;
	}
	reverse(L, L + n);
	reverse(R, R + n);
//	for (int i = 0; i < n; i++)
//		printf("%d", L[i]);
//	puts("");
//	for (int i = 0; i < n; i++)
//		printf("%d", R[i]);
//	puts("");
	ll ans = rec(0, 0, 0, 0, 0);
	printf(I64, ans);
}

