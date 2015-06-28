
#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[2000][2000];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &a[i]);
	set <int> s;
	for (int i = 0; i < n; i++)
	{
		int G, S;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'G')
				G = j;
			if (a[i][j] == 'S')
				S = j;
		}
		if (G > S)
		{
			puts("-1");
			return 0;
		}
		s.insert(S - G);
	}
	printf("%d", int(s.size()));
}