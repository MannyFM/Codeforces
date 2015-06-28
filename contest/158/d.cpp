
#include <bits/stdc++.h>

using namespace std;

int n, t[20012];
int ans;

void check(int v)
{
	vector <int> out (v, 0);
	for (int i = 0; i < n; i++)
		out[i % v] += t[i];
	/*
	cout << v << '\n';
	for (int i = 0; i < v; i++)
		cout << out[i] << " ";
	puts("");
	*/
	for (int i = 0; i < v; i++)
		ans = max(ans, out[i]);
}		

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]), ans += t[i];
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (n / i > 2)
				check(i);
			if (i > 2)
				check(n / i);
		}
	}
	printf("%d", ans);
}