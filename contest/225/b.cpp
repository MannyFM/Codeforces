
#include <bits/stdc++.h>

using namespace std;

long long f[300];

int n, k;

long long fk(int i)
{
	if (i < k)
		return 0;
	if (i == k)
		return 1;
	if (f[i])
		return f[i];
	f[i] = 0;
	for (int t = i - k; t < i; t++)
		f[i] += fk(t);
	return f[i];
}

int main()
{
	scanf("%d%d", &n, &k);
	printf("%I64d", fk(n));
}