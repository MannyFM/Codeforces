
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(3e4)

int n, d;
int a[maxn + 12], mx;
vector <vector<int>> dp;

int rec(int v, int l)
{
	if (v > mx)
		return 0;
	//cerr << v << " ";
	if (dp[v][l] != -1)
		return dp[v][l];
	int ans = 0;
	for (int i = l - 1; i <= l + 1; i++)
	{
		if (i > 0 && v + i <= maxn)
		{
			ans = max(rec(v + i, i), ans);
		}
	}
	dp[v][l] = ans + a[v];
	return ans + a[v];
}

int main()
{
	scanf("%d%d", &n, &d);
	int qq;
	for (int i = 0; i < n; i++)
		scanf("%d", &qq), a[qq]++, mx = max(mx, qq);
	mx++;
	int maxl = 0;
	int v = d;
	for (int i = d + 1; v < maxn; i++)
	{
		v += i;
		maxl = max(maxl, i);
	}
	vector <int> buf(maxl, -1);
	for (int i = 0; i <= maxn; i++)
	{
		dp.push_back(buf);
	}
	//printf("%d\n", maxl);
	int ans = rec(d, d);
	printf("%d", ans);
}