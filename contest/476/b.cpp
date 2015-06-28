
#include <bits/stdc++.h>

using namespace std;

char s1[12], s2[12];
int ans, n, pos, all;

void solve(int v = 0, int now_pos = 0)
{
	if (v == n)
	{
		all++;
		if (now_pos == pos)
			ans++;
		return;
	}
	if (s2[v] == '+' || s2[v] == '?')
		solve(v + 1, now_pos + 1);
	if (s2[v] == '-' || s2[v] == '?')
		solve(v + 1, now_pos - 1);
}

int main()
{
	scanf("%s%s", s1, s2);
	n = strlen(s1);
	for (int i = 0; i < n; i++)
		if (s1[i] == '+')
			pos++;
		else
			pos--;
	solve();
	double res = (ans + .0) / all;
	printf("%.09f", res);
}