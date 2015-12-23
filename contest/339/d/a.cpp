
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
//#define fn ""

int n, m;
int t[4 * maxn];
int a[maxn];

void build(int v, int tl, int tr, bool f)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm, !f);
	build(v + v + 1, tm + 1, tr, !f);
	if (f)
		t[v] = t[v + v] | t[v + v + 1];
	else
		t[v] = t[v + v] ^ t[v + v + 1];
}

void upd(int v, int tl, int tr, int pos, int val, bool f)
{
	if (tl == tr)
	{
		t[v] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, val, !f);
	else
		upd(v + v + 1, tm + 1, tr, pos, val, !f);
	if (f)
		t[v] = t[v + v] | t[v + v + 1];
	else
		t[v] = t[v + v] ^ t[v + v + 1];

}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	int N = 1 << n;
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	bool f = n & 1;
	build(1, 1, N, f);
	for (int i = 1; i <= m; i++)
	{
		int p, b;
		scanf("%d%d", &p, &b);
		upd(1, 1, N, p, b, f);
		printf("%d\n", t[1]);
	}
}

