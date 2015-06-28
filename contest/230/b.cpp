
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e6 + 12)

bool pr[maxn];
int n;
long long a[maxn];

int main()
{
	pr[0] = pr[1] = 1;
	for (int i = 2; i * i <= maxn; i++)
	{
		if (pr[i])
			continue;
		for (int j = i * 2; j <= maxn; j += i)
			pr[j] = 1;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d", a + i);
		long long x = (long long)(sqrt(a[i] + .0));
		if (x * x == a[i] && !pr[x])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}