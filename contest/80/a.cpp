
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
	if (x == 0 || x == 1)
		return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i = n + 1;
	while(!is_prime(i))
		i++;
	puts(m == i ? "YES" : "NO");
}