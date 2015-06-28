
#include <bits/stdc++.h>

using namespace std;

string s[4];
int sz[4];

int main()
{
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	sz[0] = int(s[0].size()) - 2;
	sz[1] = int(s[1].size()) - 2;
	sz[2] = int(s[2].size()) - 2;
	sz[3] = int(s[3].size()) - 2;
	int ans = -1;
	for (int i = 0; i < 4; i++)
	{
		int fl = 1;
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				continue;
			if (sz[i] * 2 <= sz[j])
				continue;
			fl = 0;
			break;
		}
		if (fl)
		{
			//sz[i] * 2 < any size
			//printf("!%d ", i);
			if (ans != -1)
			{
				puts("C");
				return 0;
			}
			ans = i;
			continue;
		}
		fl = 1;
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				continue;
			if (sz[i] >= sz[j] * 2)
				continue;
			fl = 0;
			break;
		}
		//sz[i] * 2 >= any size
		if (fl)
		{
			//printf("?%d ", i);
			if (ans != -1)
			{
				puts("C");
				return 0;
			}
			ans = i;
			continue;
		}
	}
	if (ans == -1)
		ans = 2;
	printf("%c", ans + 'A');
}