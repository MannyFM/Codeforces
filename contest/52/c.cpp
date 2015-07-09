#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
int const maxn = 200000 + 12;
int const inf = int(1e9) + 7;
ll const linf = ll(1e18) + 7;

ll t[4 * maxn], add[4 * maxn];
ll a[maxn];
int n;

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
}

void push(int v, int tl, int tr)
{
	if (!add[v])
		return;
	if (tl != tr)
	{
		add[v + v] += add[v];
		add[v + v + 1] += add[v];
	}
	t[v] += add[v];
	add[v] = 0ll;
}

void upd(int v, int tl, int tr, int l, int r, ll x)
{
	//printf("%d %d %d %d %d %I64d  %d %d\n", v, tl, tr, l, r, x, t[v], add[v]);
	if (tr < l || tl > r)
		return;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		add[v] += x;
		push(v, tl, tr);
		//printf("!%d %d %d %d %d %I64d  %d %d\n", v, tl, tr, l, r, x, t[v], add[v]);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, x);
	upd(v + v + 1, tm + 1, tr, l, r, x);
	push(v + v, tl, tm);
	push(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
}

ll get(int v, int tl, int tr, int l, int r)
{
	//printf("%d %d %d %d %d  %d %d\n", v, tl, tr, l, r, t[v], add[v]);
	if (tr < l || tl > r)
		return linf;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v + v, tl, tm, l, r),
		get(v + v + 1, tm + 1, tr, l, r));
}

void UPD(int l, int r, ll x)
{
	if (l <= r)
	{
		upd(1, 0, n - 1, l, r, x);
		return;
	}
	upd(1, 0, n - 1, l, n - 1, x);
	upd(1, 0, n - 1, 0, r, x);
}

ll GET(int l, int r)
{
	if (l <= r)
		return get(1, 0, n - 1, l, r);
	return min(get(1, 0, n - 1, l, n - 1),	get(1, 0, n - 1, 0, r));
}

void parse(string s)
{
	int a = -inf, b = -inf, c = -inf;
	int k = sscanf(s.c_str(), "%d%d%d", &a, &b, &c);
	//printf("%d  %d %d %d\n", k, a, b, c);
	if (k == 3)
		UPD(a, b, c + 0ll);
	else
		printf("%I64d\n", GET(a, b));
}

int main()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d ", a + i);
	build(1, 0, n - 1);
	int m;
	scanf("%d\n", &m);
	string s;
	for (int i = 1; i <= m; i++)
	{
		getline(cin, s);
		parse(s);
		//puts("");
	}
}