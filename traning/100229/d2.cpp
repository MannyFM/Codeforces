
#include <bits/stdc++.h>

using namespace std;

#define maxn 4 * 1000 * 1000 + 12
#define mod 1743

int n, k;
long long us[mod + 12];

inline int get(int x)
{
	int ans = (((132ll * x * x) % mod * x) % mod + ((77ll * x) * x) % mod + (1345ll * x) % mod + 1577ll) % mod;
	return ans % mod;
}

int main()
{
	freopen("kth.in", "r", stdin);
	freopen("kth.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int mx = 0;
	for (int i = 1; i <= n; i++)
		us[get(i)]++, mx = max(mx, get(i));
	if (n == m)
	{
		printf("%d", mx);
		return 0;
	}
	for (int i = 0; i < mod; i++)
		if (k <= us[i])
		{
			printf("%d", i);
			break;
		}
		else
			k -= us[i];
	
}
