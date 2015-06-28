
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "bigwall"
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

struct item
{
	int x, add;
	item() {};
	item(int x) : x(x), add(0) {};
};

item t[4 * maxn];

void push(int v, int tl, int tr)
{
	if (!t[v].add)
		return;
	t[v].x += t[v].add;
	if (tl != tr)
	{
		t[v + v].add += t[v].add;
		t[v + v + 1].add += t[v].add;
	}
	t[v].add = 0;
}

void build(int v, int tl, int tr)
{
	t[v] = item(0);
	if (tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
}

void update(int v, int tl, int tr, int l, int r, int add)
{
	if (l > r)
		return;
	push(v, tl, tr);
	if (tl == l && tr == r)
	{
		t[v].add += add;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), add);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, add);
	push(v + v, tl, tm);
	push(v + v + 1, tm + 1, tr);
	t[v].x = max(t[v + v].x, t[v + v + 1].x);
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		 return -inf;
	push(v, tl, tr);
	if (tl == l && tr == r)
		return t[v].x;
	int tm = (tl + tr) >> 1;
	return max(get(v + v, tl, tm, l, min(r, tm)),
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int n, m, l, r, x;
string s;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] == 'b')
		{
			scanf("%d%d%d", &l, &r, &x);
			update(1, 1, n, l, r, x);
		}
		if (s[0] == 't')
		{
			scanf("%d%d", &l, &r);
			int ans = get(1, 1, n, l, r);
			printf("%d\n", ans);
		}
	}
}