
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[3030], b[3030];
multiset <int> g;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < m; i++)
		scanf("%d", b + i), g.insert(b[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto it = g.lower_bound(a[i]);
		if (it == end(g))
			ans++;
		else
			g.erase(it);
	}
	printf("%d", ans);
}