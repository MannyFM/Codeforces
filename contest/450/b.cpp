
#include <bits/stdc++.h>

using namespace std;

const int mod = (int)(1e9 + 7);

int x, y, n;
int f[120];

int main()
{
	scanf("%d%d%d", &x, &y, &n);
	f[0] = (x + mod) % mod;
	f[1] = (y + mod) % mod;
	for (int i = 2; i < 12; i++)
		f[i] = (f[i - 1] - f[i - 2] + mod) % mod;
	int i = (n + 5) % 6 ;
	printf("%d", f[i]);
		
}