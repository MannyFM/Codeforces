
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> v;
vector <pair<int, int>> t;

int n, k, a[2020];
int fl = 0;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int b = 1; b <= 1000; b++)
	{
		v.clear();
		for (int i = 1, h = b; i <= n; i++, h += k)
			if (h != a[i])
				v.push_back(make_pair(i, h - a[i]));
		if (!fl || int(v.size()) < int(t.size()))
		{
			t = v;
			fl = 1;
		}
	}
	printf("%d\n", int(t.size()));
	for (auto i : t)
	{
		char _char = '+';
		if (i.second> 0)
			_char = '+';
		else
			_char = '-';
		printf("%c %d %d\n", _char, i.first, abs(i.second));
	}
}