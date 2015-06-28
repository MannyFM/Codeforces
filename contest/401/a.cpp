
#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[2000];

int sum, cnt;

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), sum += a[i];
	sum = abs(sum);
	while (sum > 0)
	{
		sum -= x;
		cnt++;
	}
	cout << cnt;
}