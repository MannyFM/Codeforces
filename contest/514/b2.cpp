#include <bits/stdc++.h>

using namespace std;

int n, X, Y;
int x[1010], y[1010];
int us[1010];
int A, B, C;

void pre(int x, int y)
{
	A = y - Y;
	B = X - x;
	C = x * Y - X * y;
}

bool check(int x, int y)
{
	return A * x + B * y + C == 0;
}

int main()
{
	scanf("%d%d%d", &n, &X, &Y);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x + i, y + i), us[i] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (us[i])
			continue;
		pre(x[i], y[i]);
		us[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (us[j] || i == j)
				continue;
			if (check(x[j], y[j]))
			{
				us[j] = 1;
			}
		}
		ans++;
	}
	printf("%d", ans);
}