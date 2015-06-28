
#include <bits/stdc++.h>

using namespace std;

int n, a[200], sum, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), sum += a[i];
	for (int i = 0; i < n; i++)
		ans += ((sum - a[i]) % 2 == 0);
	printf("%d", ans);
}