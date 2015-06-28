
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define inf (int)(16714589)

int m, n, t[4 * maxn], a[maxn];

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

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return inf;
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v + v, tl, tm, l, min(r, tm)),
			get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int l[maxn], r[maxn], ans[maxn];

int main()
{
	freopen("sparse.in", "r", stdin);
	freopen("sparse.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &a[1]);
	for (int i = 2; i <= n; i++)
		a[i] = (23 * a[i - 1] + 21563) % 16714589;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		if (i == 1)
		{
			scanf("%d%d", &l[i], &r[i]);
		}
		ans[i] = get(1, 1, n, l[i], r[i]);
		l[i + 1] = ((17 * l[i] + 751 + ans[i] + 2 * (i + 1)) % n) + 1;
		r[i + 1] = ((13 * r[i] + 593 + ans[i] + 5 * (i + 1)) % n) + 1;
		
	}
	for (int i = 1; i <= m; i++)
		printf("%d %d %d\n", l[i], r[i], ans[i]);
	puts("");

	printf("%d %d %d", l[m], r[m], ans[m]);

}