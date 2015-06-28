
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, m;
int x[maxn], y[maxn];
int a[maxn], b[maxn];
int us[maxn];
int ans[2];
multiset <int> s[1500];
set <int> just;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", x + i, y + i);
	}
	for (int j = 0; j < m; j++)
	{
		scanf("%d%d", a + j, b + j);
		s[b[j]].insert(a[j]);
		just.insert(b[j]);
	}
	for (int i = 0; i < n; i++)
	{
		if (s[y[i]].empty())
			continue;
		auto it = s[y[i]].find(x[i]);
		if (it != end(s[y[i]]))
		{
			ans[0]++, s[y[i]].erase(it);
			us[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (us[i] || s[y[i]].empty())
			continue;
		auto it = s[y[i]].begin();
		if (it != end(s[y[i]]))
		{
			ans[1]++;
			s[y[i]].erase(it);
			us[i]++;
		}
	}
	printf("%d %d", ans[0] + ans[1], ans[0]);
}