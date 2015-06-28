
#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x) * (x)

int n, k;
int x[200], y[200];
double ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x + i, y + i);
	for (int j = 1; j < n; j++)
	{
		ans += sqrt(sqr(x[j] + .0 - x[j - 1]) + sqr(y[j] + .0 - y[j - 1]));
	}
	printf("%.09f", ans * k / 50);
		
}