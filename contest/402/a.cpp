
#include <bits/stdc++.h>

using namespace std;

int k, n, a, b, v;

int main()
{
	scanf("%d%d%d%d", &k, &a, &b, &v);
	while (a > 0)
	{
		int cnt = min(k, b + 1);
		a -= cnt * v;
		b -= cnt - 1;
		n++;
	}
	printf("%d", n);
}