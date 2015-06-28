
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 7)
#define inf (int)(1e9 + 7)
#define pb push_back
#define ll long long
#define f first
#define s second
#define mp make_pair

int a, b;

bool check (int x)
{
	return (a % x == b);
}

int main()
{
	int c;
	scanf("%d%d", &a, &b);
	c = a - b;
	if (c == 0)
	{
		puts("infinity");
		return 0;
	}
	if (c < 0)
	{
		puts("0");
		return 0;
	}
	int ans = 0;
	for (int i = 1; i * i <= c; i++)
	{
		if (c % i == 0)
		{
			ans += check(i);
			if (c / i != i)
				ans += check(c / i);
		}
	}
	printf("%d", ans);
}