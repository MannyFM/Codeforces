
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1010], b[1010];

int calc_min()
{
	for (int i = 1; i <= m; i++)
		b[i] = a[i];
	int ans = 0;
	int j = 1;
	for (int i = 1; i <= m; i++)
	{
		for (; j <= n && b[i]; j++)
		{
			//printf(" %d %d %d\n", i, j, b[i]);
			ans += b[i];
			b[i]--;
		}
	}
	//puts("");
	return ans;
}

int calc_max()
{
	multiset <int> s;
	for (int i = 1; i <= m; i++)
		s.insert(a[i]);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if (s.empty())
			break;
		auto it = s.end();
		it--;
		int now = *it;
		s.erase(it);
		ans += now;
		//printf("%d ", now);
		if (now > 1)
			s.insert(now - 1);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", a + i);
	sort(a + 1, a + m + 1);
	printf("%d %d", calc_max(), calc_min());
}