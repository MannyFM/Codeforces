
#include <bits/stdc++.h>

using namespace std;

#define maxn 4 * 1000 * 1000 + 12
#define mod 1743

int n, k;
int us[mod + 12];

int get(int x)
{
	int ans = (((132ll * x * x) % mod * x) % mod + ((77ll * x) % mod * x) % mod + (1345ll * x) % mod + 1577ll) % mod;
	return ans % mod;
}

int main()
{
	freopen("kth.in", "r", stdin);
	freopen("kth.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < mod; i++)
		us[get(i)]++;
	int period = n / mod;
	for (int i = 0; i < mod; i++)
		us[i] *= period;
	for (int i = period * mod + 1; i <= n; i++)
		us[get(i)]++;
	
	int now = 0;
	for (int i = 0; i < mod; i++)
	{
		now += us[i];
		if (now >= k)
		{
			printf("%d", i);
			return 0;
		}
	}
	
}