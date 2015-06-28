
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(5e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

int n, a[maxn];
ll pre[maxn], suf[maxn];
int c[maxn], cnt[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	if (pre[n] % 3)
	{
		puts("0");
		return 0;
	}
	for (int i = n; i; i--)
		suf[i] = suf[i + 1] + a[i];
	for (int i = n; i; i--)
		c[i] = suf[i] == pre[n] / 3;
	cnt[n] = c[n];
	for (int i = n; i; i--)
		cnt[i] = cnt[i + 1] + c[i];
	ll sum = pre[n] / 3, ans = 0;
	for (int i = 2; i <= n; i++)
		if (pre[i] == sum)
			ans += cnt[i + 1];
	printf("%I64d", ans);
}