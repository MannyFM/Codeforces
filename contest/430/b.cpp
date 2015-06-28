
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int n, k, x, c[110], ans;
vector <pair<int, int>> a;

int main()
{
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	
	a.pb(mp(c[1], 1));
	for (int i = 2; i <= n; i++)
		if (c[i] == a.back().first)
			a.back().second++;
		else
			a.pb(mp(c[i], 1));
	
	for (int i = 0; i < int(a.size()); i++)
	{
		if (a[i].first != x || a[i].second < 2)
			continue;
		int l = i - 1;
		int r = i + 1;
		int now = a[i].second;
		while (l >= 0 && r < n && a[l].first == a[r].first && a[l].second + a[r].second > 2)
		{
			now += a[l].second + a[r].second;
			l--, r++;
		}
		ans = max(ans, now);
	}
	printf("%d", ans);
}