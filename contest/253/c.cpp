
#include <bits/stdc++.h>

using namespace std;

int a, b;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &a, &b);
	if (a < b)
	{
		for(int i = 0; i < a; i++)
			printf("GB");
		b -= a;
		for(int i = 0; i < b; i++)
			printf("G");
	}
	else
	{
		for(int i = 0; i < b; i++)
			printf("BG");
		a -= b;
		for(int i = 0; i < a; i++)
			printf("B");
	}
}