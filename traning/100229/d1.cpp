
#include <bits/stdc++.h>

using namespace std;

int n, k;
int us[1743];

int get(int x)
{
	return (((132ll * x * x) % 1743 * x) % 1743 + ((77ll * x) % 1743 * x) % 1743 + (1345ll * x) % 1743 + 1577ll) % 1743;
}

int main()
{
	//freopen("kth.in", "r", stdin);
	//freopen("kth.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		us[get(i)]++;
	for (int i = 0; i < 1743; i++, k -= us[i])
		if (k <= us[i])
		{
			printf("%d", i);
			break;
		}
	
}