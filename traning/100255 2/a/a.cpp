
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
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "mushrooms"

int n, lg[maxn];
int s[19][maxn];
int a[maxn];

void pre()
{
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 0; i < n; i++)
		s[0][i] = a[i];
	for (int k = 1; k <= lg[n]; k++)
		for (int i = 0; i < n; i++)
			s[k][i] = max(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
}

int get_max(int l, int r)
{
	if (l > r)
		swap(l, r);
	int k = lg[r - l + 1];
	//printf("%d %d  %d\n", l, r, max(s[k][l], s[k][r - (1 << k) + 1]));
	return max(s[k][l], s[k][r - (1 << k) + 1]);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	pre();
	int m, r, R, H = 0;
	ll ans = 0ll;
	scanf("%d%d%d", &m, &r, &R);
	H = get_max(R, r);
	ans += H;
	for (int i = 1; i < m; i++)
	{
		H = get_max(R, (r * H + H * 1ll * H) % n);
		ans += H;
	}
	printf(I64, ans);
}
