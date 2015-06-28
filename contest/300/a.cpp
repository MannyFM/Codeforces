
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

bool pos, neg, nu;
int n, a[200];
vector <int> b[3];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0 && !neg)
		{
			neg = 1;
			b[0].pb(a[i]);
		}
		else
		if (a[i] > 0 && !pos)
		{
			pos = 1;
			b[1].pb(a[i]);
		}
		else
		{
			if (a[i] == 0)
				nu = 1;
			b[2].pb(a[i]);
		}
	}
	if (!pos)
	{
		for (int i = 0; i < b[2].size(); i++)
			if (b[2][i] < 0)
			{
				b[1].pb(b[2][i]), b[2].erase(b[2].begin() + i);
				break;
			}
		for (int i = 0; i < b[2].size(); i++)
			if (b[2][i] < 0)
			{
				b[1].pb(b[2][i]), b[2].erase(b[2].begin() + i);
				break;
			}
	}
	for (int u = 0; u < 3; u++)
	{
		cout << b[u].size() << " ";
		for (int i = 0; i < b[u].size(); i++)
			cout << b[u][i] << " ";
		puts("");
	}
}