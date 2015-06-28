
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, p1, p2, p3;
int t2, t3;
int l[200], r[200];

int f(int l, int r)
{
	int T1 = min(t2, r - l);
	int T2 = min(t3, r - l - T1);
	int T3 = r - l - T1 - T2;
	return T1 * p1 + T2 * p2 + T3 * p3;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &p1, &p2, &p3);
	scanf("%d%d", &t2, &t3);
	ll ans = 0ll;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", l + i, r + i);
	for (int i = 1; i <= n; i++)
		ans += (r[i] - l[i]) * 1ll * p1;
	for (int i = 2; i <= n; i++)
		ans += f(r[i - 1], l[i]);
	printf("%I64d", ans);

}