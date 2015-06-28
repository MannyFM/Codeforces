
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
#define fn "a"
#define f first
#define s second
int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int r, g, b;
int R, G, B;
ll ans;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &r, &g, &b);
	for (int i = 0; i <= min(3, min(r, g, b)); i++)
	{
		R = r, G = g, B = b;
		R -= i;
		G -= i;
		B -= i;
		ll now = i;
		now += R / 3 + G / 3 + B / 3;
		ans = max(ans, now);
	}
	printf("%I64d", ans);
}