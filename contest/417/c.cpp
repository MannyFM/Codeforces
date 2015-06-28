
#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	if (n < 2 * k + 1)
	{
		puts("-1");
		return 0;
	}
	vector <pair<int, int>> v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			v.push_back(make_pair(i, (i + j - 1 + n) % n + 1));
	printf("%d\n", int(v.size()));
	for (auto i : v)
		printf("%d %d\n", i.first, i.second);
}