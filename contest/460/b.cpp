
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9)

long long a, b, c;

int f(long long x)
{
	int ans = 0;
	while (x > 0)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

long long pw(int x, int a)
{
	long long ans = 1;
	for (int i = 0; i < a; i++)
		ans *= x;
	return ans;
}

int main()
{
	scanf("%I64d%I64d%I64d", &a, &b, &c);
	vector <int> ans;
	for (int sx = 1; sx <= 81; sx++)
	{
		long long fx = b * pw(sx, a) + c;
		if (sx == f(fx) && 0 < fx && fx < inf)
			ans.push_back(fx);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
