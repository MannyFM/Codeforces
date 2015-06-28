
#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[200], y[200], X[200];
int l[200], r[200];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]), X[i] = x[i];
	for (int i = 0; i < m; i++)
		scanf("%d%d", l + i, r + i);
	sort(x, x + n);
	for (int i = 0; i < n; i++)
		y[x[i]] = i & 1;
	for (int i = 0; i < n; i++)		
		printf("%d ", y[X[i]]);
}