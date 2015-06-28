
#include <bits/stdc++.h>

using namespace std;

int s1, s2, s3;
int a, b, c;

int main()
{
	scanf("%d%d%d", &s1, &s2, &s3);
	a = (int)sqrt(s1 * 1ll * s2 / s3);
	b = (int)sqrt(s1 * 1ll * s3 / s2);
	c = (int)sqrt(s3 * 1ll * s2 / s1);
	printf("%I64d", 4ll * (a + b + c));
}