
#include <bits/stdc++.h>

using namespace std;

int n, k, a[40];
int us[10000];
vector <int> v[40];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", a + i), v[i].push_back(a[i]), us[a[i]]++;
	int j = 1;
	for (int i = 1; i <= k; i++)
	{
		while ((int)v[i].size() < n)
		{
			while (us[j])
				j++;
			v[i].push_back(j);
			j++;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		for (auto j : v[i])
			printf("%d ", j);
		puts("");
	}
}