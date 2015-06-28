
#include <bits/stdc++.h>

using namespace std;

int n, v, k, s;
set <int> ans;

int main()
{
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &s);
			if (v > s)
				ans.insert(i + 1);
		}
	}
	cout << ans.size() << '\n';
	for (set <int> :: iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it <<  " ";
}