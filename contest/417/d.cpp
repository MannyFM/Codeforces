
#include <bits/stdc++.h>

using namespace std;

struct item
{
	int x, k, sz;
	vector <int> v;
};

int n, m, b;
int x[200], k[200], mi[200];
int dp[(1 << 20) + 4];
vector <int> v[200];

item a[200];

bool cmp(item a, item b)
{
	return a.k > b.k;
}

int gen(int i, int mask)
{
	for (int j = 0; j < (int)a[i].v.size(); j++)
		mask |= (1 << a[i].v[j]);
	return mask;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x[i], &k[i], &mi[i]);
		int buf;
		for (int j = 1; j <= mi[i]; j++)
			scanf("%d", &buf), v[i].push_back(buf);
		a[i].v = v[i];
		a[i].x = x[i];
		a[i].k = k[i];
		a[i].sz = mi[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		int 
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < int(a[i].v.size()); j++)
			printf("%d ", a[i].v[j]);
		printf("\n%d\n", gen(i, 0));

	}
}