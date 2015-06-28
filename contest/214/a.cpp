
#include <bits/stdc++.h>

using namespace std;

int n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int a = 0; a <= 100000; a++)
	{
		int b1 = n - a * a, b2= m - a;
		if (b1 >= 0 && b2 >= 0 && b1 == sqrt(b2))
		{
			ans++;
//			printf("%d %d\n", a, b1);
		}	
	}
	printf("%d", ans);
}