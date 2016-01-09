
#include <bits/stdc++.h>

using namespace std;

int n, r[200];
double ans = 0;
const double Pi = acos(-1);

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", r + i);
	sort(r, r + n);
	int k = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		ans += Pi * r[i] * r[i] * k;
		k *= -1;
	}
	printf("%.010f", ans);
}
