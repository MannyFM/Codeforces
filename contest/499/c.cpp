
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(3e3 + 12)
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

int xa, ya, xb, yb, ans;
int n, a, b, c;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d", &xa, &ya, &xb, &yb, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		ll f = a * 1ll * xa + b * 1ll * ya + c;
		ll g = a * 1ll * xb + b * 1ll * yb + c;
		if ((f > 0 && g < 0) || (f < 0 && g > 0))
			ans++;
	}
	printf("%d", ans);
}