
#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, ans = 0;

int main()
{
	scanf("%d%d%d%d", &n, &a, &b, &c);
	for (int i = 0; i <= n / a; i++)
		for (int j = 0; j <= (n - a * i) / b; j++)
		{
			int k = (n - i * a - j * b) / c;
			if (i * a + j * b + k * c == n && i + j + k > ans)
			{
				ans = i + j + k;
			}
		}
	printf("%d", ans);
}