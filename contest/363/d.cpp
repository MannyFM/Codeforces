
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "d"
#define F first
#define S second
#define LOCAL

int n, m;
ll p[maxn], b[maxn], a;

ll f(int cnt)
{
	ll sum = 0ll;
	for (int i = 1; i <= cnt; i++)
		sum += max(0ll, p[cnt - i + 1] - b[i]);
	return sum;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%I64d", &n, &m, &a);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", b + i);
	for (int i = 1; i <= m; i++)
		scanf("%I64d", p + i);
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	sort(p + 1, p + m + 1);
	int L = -1, R = min(n, m) + 1;
	while (R - L > 1)
	{
		int mid = (L + R) >> 1;
		if (f(mid) <= a)
			L = mid;
		else
			R = mid;
	}
	ll sum = -a;
	for (int i = 1; i <= L; i++)
		sum += p[i];
	printf("%d %I64d", L, max(sum, 0ll));
}