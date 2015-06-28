
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, m, x, y;
int a[maxn], b[maxn];
multimap <int, int> s;
vector <pair<int, int>> v;

int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", b + i);
		s.insert(make_pair(b[i], i));
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto it = s.lower_bound(a[i] - x);
		if (it == end(s) || it -> first > a[i] + y)
			continue;
		ans++;
		v.push_back(make_pair(i, it -> second));
		s.erase(it);
	}
	printf("%d\n", v.size());
	for (auto i : v)
		printf("%d %d\n", i.first + 1, i.second + 1);
}