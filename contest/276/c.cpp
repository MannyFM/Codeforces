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
//#define fn ""

int n, m;
int a[maxn], l, r;
int cnt[maxn], b[maxn];
ll ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		cnt[l]++, cnt[r + 1]--;
	}
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + cnt[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
		ans += a[i] * 1ll * b[i];
	printf(I64, ans);
}
