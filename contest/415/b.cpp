
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, a, b, w, x;

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	int g = __gcd(a, b);
	while(n--)
	{
		scanf("%d", &x);
		ll s = (x * a) / b;
		int l = 0, r = x + 1;
		while (r - l > 1)
		{
			int m = (l + r) >> 1;
			if (((x - m) * 1ll * a) / b == s)
				l = m;
			else
				r = m;
		}
		printf("%d ", l);
	}
}