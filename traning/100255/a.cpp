
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define maxb int(5e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "mushrooms"
#define f first
#define s second
#define LOCAL

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

int t[4 * maxn];
int n, h[maxn];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = h[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return -inf;
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return max(get(v + v, tl, tm, l, min(r, tm)), 
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", h + i);
	build(1, 0, n - 1);
	int l, r, m;
	scanf("%d%d%d", &m, &l, &r);
	long long ans = 0, H;
	H = get(1, 0, n - 1, l, r);
	ans += H;
	for (int i = 1; i < m; i++)
	{
		int L = min(r, (int)((l * 1ll * H + H * 1ll * H) % n)), R = max(r, (int)((l * 1ll * H + H * 1ll * H) % n));
		H = get(1, 0, n - 1, L, R);
		ans += H;
	}
	printf("%I64d", ans);
}