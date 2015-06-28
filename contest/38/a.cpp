
#include <bits/stdc++.h>

using namespace std;

int n, d[200];
int a, b, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		scanf("%d", &d[i]);
	scanf("%d%d", &a, &b);
	for (int i = a + 1; i <= b; i++)
		ans += d[i];
	printf("%d", ans);
}