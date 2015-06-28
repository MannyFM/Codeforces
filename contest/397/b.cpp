
#include <bits/stdc++.h>

using namespace std;

int n, t, l, r, k;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &l, &r);
		k = n / l;
		puts(r * k >= n ? "Yes" : "No");
	}
}