
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
#define fn "f"

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

int T[21][4 * maxn];
bool add[21][4 * maxn];
int a[maxn], mx_k = 20; ///------------------------------------------------------------------------------------------------------------------------------

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		for (int i = 0; i < mx_k; i++)
			T[i][v] = (a[tl] & (1 << i)) > 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	for (int i = 0; i < mx_k; i++)
		T[i][v] = T[i][v + v] + T[i][v + v + 1];
}

void push(int k, int v, int tl, int tr)
{
	if (!add[k][v] || tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	add[k][v + v] ^= 1;
	add[k][v + v + 1] ^= 1;
	T[k][v + v] = (tm - tl + 1) - T[k][v + v];
	T[k][v + v + 1] = (tr - tm) - T[k][v + v + 1];
	add[k][v] = 0;
}

int get(int k, int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return 0;
	push(k, v, tl, tr);
	if (l <= tl && tr <= r)
		return T[k][v];
	int tm = (tl + tr) >> 1;
	return get(k, v + v, tl, tm, l, r)
		+ get(k, v + v + 1, tm + 1, tr, l, r);
}

void upd(int k, int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		add[k][v] ^= 1;
		T[k][v] = (tr - tl + 1) - T[k][v];
		push(k, v, tl, tr);
		return;
	}
	push(k, v, tl, tr);
	int tm = (tl + tr) >> 1;
	upd(k, v + v, tl, tm, l, r);
	upd(k, v + v + 1, tm + 1, tr, l, r);
	T[k][v] = T[k][v + v] + T[k][v + v + 1];
}

void print(int v, int tl, int tr)
{
	if (tl == tr)
	{
		for (int i = 0; i < mx_k; i++)
			printf("%d ", T[i][v]);
		puts("");
		return;
	}
	int tm = (tl + tr) >> 1;
	print(v + v, tl, tm);
	print(v + v + 1, tm + 1, tr);
}

void out(int v, int tl, int tr)
{
	for (int i = 0; i < mx_k; i++)
		push(i, v, tl, tr);
	if (tl == tr)
		return;
	printf("T[%d] [%d %d]\n", v, tl, tr);
	for (int i = 0; i < mx_k; i++)
		printf("%d ", T[i][v]);
	puts("");
	int tm = (tl + tr) >> 1;
	out(v + v, tl, tm);
	out(v + v + 1, tm + 1, tr);
}

int n;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	int m, l, r, t, x;
	scanf("%d", &m);
//	out(1, 1, n);
//	puts("");
//	print(1, 1, n);
//	puts("");
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &t, &l, &r);
		if (t == 2)
		{
			scanf("%d", &x);
//			printf("%d:\n", x);
			for (int i = 0; i < mx_k; i++)
			{
//				printf("%d ", (x & (1 << i)) > 0);
				if (x & (1 << i))
					upd(i, 1, 1, n, l, r);
			}
//			puts("");
//			out(1, 1, n);
//			puts("");
//			print(1, 1, n);
//			puts("");
		}
		else
		{
			ll ans = 0ll;
			for (int i = 0; i < mx_k; i++)
			{
				int cnt = get(i, 1, 1, n, l, r);
//				printf("%d ", cnt);
				ans += (1ll << i) * cnt;
			}
//			puts("");
			printf(I64 "\n", ans);
		}
	}
}

