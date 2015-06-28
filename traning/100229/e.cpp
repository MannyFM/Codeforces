
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
	freopen("kth.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	vector <int> v;
	for (int i = 1; i <= n; i++)
		us[get(i)]++;
	int mn = maxn * mod;
	for (int i = 0; i <= n; i++)
	{
		printf("%d %d %d\n", i, get(i), us[get(i)]);
		mn = min(mn, us[get(i)]);
	}
	printf("%d", mn);
}