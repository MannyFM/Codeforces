
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f(i, j) (g[p[i]][p[j]] + 0ll + g[p[j]][p[i]])

int g[6][6];
int p[6], n = 5;
ll res;

void check()
{
	ll ans = 0;
	//12345
	ans += f(1, 2);
	ans += f(3, 4);
	//2345
	ans += f(2, 3);
	ans += f(4, 5);
	//345
	ans += f(3, 4);
	//45
	ans += f(4, 5);
	res = max(res, ans);
}

int main()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	do
	{
		check();
	}
	while(next_permutation(p + 1, p + 6));
	printf("%I64d", res);
}