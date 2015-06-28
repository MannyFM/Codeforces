
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "mushrooms"
#define f first
#define s second
#define LOCAL

ll s[30][maxn];
int lg[maxn];
int n, r, R, m;
ll h[maxn];
ll ans, H;

void pre()
{
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= n; i++)
		s[0][i] = h[i];
	for (int k = 1; k <= lg[n]; k++)
		for (int i = 0; i < n; i++)
			s[k][i] = max(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
}

ll get(int l, int r)
{
	int k = lg[r - l + 1];
	return max(s[k][l], s[k][r - (1 << k) + 1]);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", h + i);
	pre();
	scanf("%d%d%d", &m, &r, &R);
	H = get(r + 1, R + 1);
	ans = H;
	for (int i = 1; i < m; i++)
	{
		int _R = R, _r = int((r * 1ll * H + H * 1ll * H) % n);
		H = get(min(_R, _r) + 1, max(_R, _r) + 1);
		ans += H;
	}
	printf("%I64d", ans);
}
