
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define mod int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, k, a[maxn];
ll F[maxn], ans, buf, carry, p;
char s[maxn];

ll bp(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a % mod;
	ll c = bp(a, b / 2);
	c = (c * 1ll * c) % mod;
	if (b & 1)
		c = (c * a) % mod;	
	return c;
}

ll C(ll n, ll k)
{
	if (n < k || k < 0)
		return 0;
	ll B = (F[n - k] * F[k]) % mod;
	return (F[n] * bp(B, mod - 2)) % mod;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - '0';
	F[0] = 1;
	for (int i = 1; i <= n; i++)
		F[i] = (F[i - 1] * i) % mod;
	carry = C(n - 2, k - 1);
	ans = (a[n] * C(n - 1, k)) % mod;
	p = 1;
	//printf("%d %I64d\n", a[n], ans);
	for (int i = n - 1; i > 0; i--)
	{
		p = (p * 10) % mod;
		buf = (carry + C(i - 1, k) * p) % mod;
		carry = (carry + C(i - 2, k - 1) * p) % mod;
		ans = (ans + buf * a[i]) % mod;
		//printf("%d %I64d\n", a[i], ans);
	}
	printf("%I64d", ans);
	
}
