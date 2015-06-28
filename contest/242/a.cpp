
#include <bits/stdc++.h>

using namespace std;

int x, y, a, b;

int main()
{
	scanf("%d%d%d%d", &x, &y, &a, &b);
	vector <pair<int, int>> v;
	for (int orel1 = a; orel1 <= x; orel1++)
	for (int orel2 = b; orel2 <= y; orel2++)
	{
		if (orel1 > orel2)
		v.push_back(make_pair(orel1, orel2));
	}
	sort(begin(v), end(v));
	printf("%d\n", int(v.size()));
	for (int i = 0; i < int(v.size()); i++)
		printf("%d %d\n", v[i].first, v[i].second);
}