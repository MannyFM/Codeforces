
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, h[maxn], m;
int r, R;
int s[22][maxn];
int lg[maxn];

int get(int l, int r)
{
	if (l > r)
		swap(l, r);
	int k = lg[r - l + 1];
	return max(s[k][l], s[k][r - (1 << k) + 1]);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", h + i);
	scanf("%d%d%d", &m, &r, &R);
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 0; i < n; i++)
		s[0][i] = h[i];
	for (int k = 1; k <= lg[n]; k++)
		for (int i = 0; i < n; i++)
			s[k][i] = max(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
	ll ans, h;
	ans = h = get(r, R);
	for (int i = 2; i <= m; i++)
	{
		h = get(R, (r * 1ll * h + h * h) % n);
		printf(I64 "\n", h);
		ans += h;
	}
	printf(I64, ans);
}

