
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, k, p[maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = n; i > n - k; i--)
		printf("%d ", i);
	for (int i = 1; i <= n - k; i++)
		printf("%d ", i);
}