
#include <bits/stdc++.h>

using namespace std;

string s;
int ans, now;

int main()
{
	cin >> s;
	int n = (int)(s.size());
	now = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i - 1] || now == 5)
		{
			ans++;
			now = 1;
		}
		else
			now++;
	}
	ans++;
	printf("%d", ans);
}