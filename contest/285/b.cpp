
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, p[maxn], s, t;

int dfs(int v, int pr = -1)
{
	//cerr << v << " " << p[v] << '\n';
	if (v == t)
		return 0;
	if (v == s && pr != -1)
		return -1;
	int k = dfs(p[v], v);
	return k != -1 ? k + 1 : k;
}

int main()
{
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i);
	printf("%d", dfs(s));
}