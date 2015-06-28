
#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
bool a[1020][1020];
int dp[1020][0], cnt[1020];

int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	char _char;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _char, a[i][j] = _char == '.';
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			cnt[j] += a[i][j];
	dp[0][0] = n - cnt[0];
	dp[0][1] = cnt[0];
	for (int i = 1; i < m; i++)
	{
		
	}
}
