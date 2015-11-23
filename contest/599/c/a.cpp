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
//#define fn ""

int a[maxn], n, pre[maxn], suf[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	pre[0] = -inf;
	suf[n + 1] = inf;
	for (int i = 1; i <= n; i++)
		pre[i] = max(pre[i - 1], a[i]);
	for (int i = n; i > 0; i--)
		suf[i] = min(suf[i + 1], a[i]);
	int ans = 1;
	for (int i = 1; i < n; i++)
		ans += pre[i] <= suf[i + 1];
	if (!ans)
		ans++;
	printf("%d", ans);
}
