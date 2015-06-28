
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
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

struct pii
{
	ll f;
	int s;
	int add;
	pii() {};
	pii(ll f, int i) : f(f), s(i), add(0) {};
};

pii min(pii a, pii b)
{
	if (a.f < b.f)
		return a;
	if (a.f > b.f)
		return b;
	if (a.s < b.s)
		return a;
	return b;
}

pii t[4 * maxn];
int n, a[maxn], m, w;

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = pii((ll)(a[tl]), tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
}

void push(int v, int tl, int tr)
{
	if (!t[v].add)
		return;
	t[v].f += t[v].add;
	if (tl != tr)
	{
		t[v + v].add += t[v].add;
		t[v + v + 1].add += t[v].add;
	}
	t[v].add = 0;
}

int get(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);
	if (l > r)
		return inf;
	if (tl == l && tr == r)
		return t[v].s;
	int tm = (tl + tr) >> 1;
	return min(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll get2(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);
	if (l > r)
		return inf;
	if (tl == l && tr == r)
		return t[v].f;
	int tm = (tl + tr) >> 1;
	return min(get2(v + v, tl, tm, l, min(r, tm)), get2(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	push(v, tl, tr);
	if (l > r)
		return;
	if (tl == l && tr == r)
	{
		t[v].add += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
	push(v + v, tl, tm);
	push(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
	t[v].add = 0;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int pos = get(1, 1, n, 1, n);
		pos = min(pos, n - w + 1);
		update(1, 1, n, pos, pos + w - 1, 1);
	}
	printf("%I64d", get2(1, 1, n, 1, n));
}