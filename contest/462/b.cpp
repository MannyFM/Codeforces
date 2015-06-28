
#include <bits/stdc++.h>

using namespace std;

int n, k, a[30];
string s;
bool cc(int i, int j)
{
	return i > j;
}

int main()
{
	scanf("%d%d", &n, &k);
	cin >> s;
	for (int i = 0; i < n; i++)
		a[(int)(s[i] - 'A')]++;
	sort(a, a + 30, cc);
	int i = 0;
	long long ans = 0ll;
	while (k)
	{
		long long p = min(k, a[i]) + 0ll;
		k -= p;
		ans += p * p;
		i++;
	}
	printf("%I64d", ans);
}