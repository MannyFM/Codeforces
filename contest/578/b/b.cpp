
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

ll pre[maxn], suff[maxn], a[maxn];
ll ans, p[maxn];
int n, k, x;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; i++)
		scanf(I64, a + i);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] | a[i];
	for (int i = n; i > 0; i--)
		suff[i] = suff[i + 1] | a[i];
	p[0] = 1ll;
	for (int i = 1; i <= k; i++)
		p[i] = p[i - 1] * x;
	ans = pre[n];
	for (int i = 1; i <= n; i++)
	{
		ll cur = pre[i - 1] | (a[i] * p[k]) | suff[i + 1];
		//printf(I64 " " I64 " " I64 " " I64 "\n", pre[i - 1], (a[i] * p[k]), suff[i + 1], pre[i - 1] | (a[i] * p[k]) | suff[i + 1]);
		ans = max(ans, cur);
	}
	printf(I64, ans);
}
