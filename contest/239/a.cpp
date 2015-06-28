
#include <bits/stdc++.h>

using namespace std;

int n, k, st, y;
vector <int> v;

int main()
{
	scanf("%d%d%d", &y, &k, &n);
	st = (y + k - 1) / k;
	st *= k;
	for(; st <= n; st += k)
	{
		//printf("%d ", st);
		if (st - y > 0)
			v.push_back(st - y);
	}
	if (v.empty())
		v.push_back(-1);
	for (auto i : v)
		printf("%d ", i);
}