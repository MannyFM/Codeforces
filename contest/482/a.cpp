
#include <bits/stdc++.h>

using namespace std;

int n, k, l, r;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - k; i++)
		cout << i << " ";
	l = n - k + 1, r = n;
	while (l < r)
	{
		cout << r-- << " " << l++ << " ";
	}
	
	if (l == r)
		cout << l;
}