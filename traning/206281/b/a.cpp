
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
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
//#define fn ""

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

int t[4 * maxn];
int add[4 * maxn];
int n, a[maxn], bal[maxn];
int l[maxn], r[maxn];

void push(int v, int tl, int tr)
{
	if (!add[v] || tl == tr)
		return;
	add[v + v] += add[v];
	add[v + v + 1] += add[v];
	t[v + v] += add[v];
	t[v + v + 1] += add[v];
	add[v] = 0;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = bal[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
	push(v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		t[v] += x;
		add[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
}

int get(int v, int tl, int tr, int pos)
{
	push(v, tl, tr);
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return get(v + v, tl, tm, pos);
	return get(v + v + 1, tm + 1, tr, pos);	
}

vector <int> L, R;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		l[i] = l[i - 1] + a[i];
	for (int i = n; i > 0; i--)	
		r[i] = r[i + 1] + !a[i];
	for (int i = 1; i <= n; i++)
		bal[i] = l[i - 1] + r[i + 1];
	for (int i = 1; i <= n; i++)
		if (a[i])
			L.pb(i);
	for (int i = n; i > 0; i--)
		if (!a[i])
			R.pb(i);
	build(1, 1, n);
	int li = 0, ri = 0;
	ll ans = 0ll;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", bal[i]);
//	puts("");
	for (int i = 1; i <= n; i++)
	{
		int lx = li >= (int)L.size() ? inf : get(1, 1, n, L[li]);
		int rx = ri >= (int)R.size() ? inf : get(1, 1, n, R[ri]);
		if (lx < rx)
		{
//			printf("%d(%d) ", L[li], lx);
			ans += lx;
			upd(1, 1, n, L[li] + 1, n, -1);
			upd(1, 1, n, L[li], L[li], inf);
			li++;
		}
		else
		{
//			printf("%d(%d) ", R[ri], rx);
			ans += rx;
			upd(1, 1, n, 1, R[ri] - 1, -1);
			upd(1, 1, n, R[ri], R[ri], inf);
			ri++;
		}
	}
	printf(I64, ans);
}
