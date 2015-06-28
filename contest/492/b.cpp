
#include <bits/stdc++.h>

using namespace std;

int n, a[1010], l;
double ans = .0;

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	ans = a[0] + .0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] + ans < a[i] - ans)
			ans = (a[i] - a[i - 1]) / 2.0;
	}
	if (a[n - 1] + ans < l)
		ans = l - a[n - 1];
	printf("%.9f", ans);
}