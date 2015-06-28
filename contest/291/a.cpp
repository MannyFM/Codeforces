
#include <bits/stdc++.h>

using namespace std;

int n, a, ans;
map <int, int> s;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a)
			s[a]++;
	}
	for (map <int, int> :: iterator it = s.begin(); it != s.end(); it++)
	{
		if ((*it).second > 2)
		{
			puts("-1");
			return 0;
		}
		ans += ((*it).second > 1);
	}
	printf("%d", ans);
}