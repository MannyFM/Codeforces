
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

int n, k;
int a[3030], b, c, ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &b, &c);
		a[b] += c;
	}
	for (int i = 1; i <= 3001; i++)
	{
		int can = k, get;
		get = min(can, a[i - 1]);
		ans += get;
		can -= get;
		get = min(can, a[i]);
		ans += get;
		a[i] -= get;
	}
	printf("%d", ans);
}