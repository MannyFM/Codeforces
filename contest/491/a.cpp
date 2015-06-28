
#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
	scanf("%d%d", &a, &b);
	c = a + b + 1;
	for (int i = 1; i <= a; i++)
		printf("%d ", i);
	for (int i = 0; i <= b; i++, c--)
		printf("%d ", c);
}