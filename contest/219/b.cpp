
#include <bits/stdc++.h>

using namespace std;

long long p, d;
long long Hex[20];

int main()
{
	scanf("%I64d%I64d", &p, &d);
	if (p < 8)
	{
		printf("%I64d", p);
		return 0;
	}
	Hex[0] = 1ll;
	for (int i = 1; i <= 18; i++)
		Hex[i] = Hex[i - 1] * 10;
	int P = p, K = 0;
	while (P % 10 == 9)
	{
		P /= 10;
		K++;
	}
	for (int k = 18; k > K; k--)
	{
		long long left = p / Hex[k];
		long long all = left * Hex[k] - 1;
		//printf("%d %I64d\n", k, all);
		if (all > 0 && all >= p - d && all <= p)
		{
			printf("%I64d", all);
			return 0;
		}
	}
	printf("%I64d", p);
}
