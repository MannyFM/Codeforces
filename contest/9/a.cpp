
#include <bits/stdc++.h>

using namespace std;

int a, b;

int main()
{
	scanf("%d%d", &a, &b);
	int c = 7 - max(a, b);
	int d = 6;
	int g = __gcd(c, d);
	printf("%d/%d", c / g, d / g);
}