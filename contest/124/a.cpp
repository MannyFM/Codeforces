
#include <bits/stdc++.h>

using namespace std;

int n, a, b, ans;

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		ans += (max(a + 1, n - b) <= i);
	printf("%d", ans);
}	
