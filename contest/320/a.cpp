
#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main()
{
	cin >> s;
	n = (int)(s.size());
	for (int i = 0; i < n; i++)
		if (s[i] != '4' && s[i] != '1')
		{
			puts("NO");
			return 0;
		}
	if (s[0] != '1')
	{
		puts("NO");
		return 0;
	}
	for (int i = n - 1; i >= 0;)
	{
		if (s[i] == '4')
		{
			if (i >= 2 && s[i - 1] == '4' && s[i - 2] == '1')
			{
				i -= 3;
				continue;
			}
			if (i >= 1 && s[i - 1] == '1')
			{
				i -= 2;
				continue;
			}
			puts("NO");
			return 0;
		}
		if (s[i] == '1')
		{
			i--;
		}

	}
	puts("YES");
}
