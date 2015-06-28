
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
#define mod int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

char s[maxn];
int n, c;
int cnt[300], mx;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++)
		cnt[s[i] + 0]++;
	for (int i = 0; i < 300; i++)
		mx = max(mx, cnt[i]);
	for (int i = 0; i < 300; i++)
		if (mx == cnt[i])
			c++;
	ll ans = 1ll;
	for (int i = 1; i <= n; i++)
		ans = (ans * c) % mod;
	printf("%I64d", ans);
}